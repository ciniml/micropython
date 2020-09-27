import machine

class AXP192(object):
    REG_EXTEN_DCDC2_OUTPUT_CONFIG = const(0x10)
    REG_OUTPUT_ENABLE = const(0x12)
    REG_LDO2_LDO3_OUTPUT_VOLTAGE = const(0x28)
    REG_ADC_ENABLE_1 = const(0x82)
    REG_VOFF_SHUTDOWN_VOLTAGE_CONFIG = const(0x31)
    REG_CHARGING_CONFIG = const(0x33)
    REG_DCDC_OPERATING_MODE = const(0x80)
    REG_COULOMB_COUNTER_CHARGE    = const(0xB0)
    REG_COULOMB_COUNTER_DISCHARGE = const(0xB4)
    REG_COULOMB_COUNTER_CONTROL = const(0xB8)
    REG_ADC_RATE_TS_CONTROL = const(0x84)
    REG_PEK_CONFIG = const(0x36)
    REG_GPIO0_FUNCTION = const(0x90)
    REG_VBUS_IPSOUT_PATH_CONFIG = const(0x30)
    REG_VHTF_CHARGE_THRESHOLD = const(0x39)
    REG_BACKUP_BATTERY_CHARGING = const(0x35)
    REG_ADC_BASE = const(0x56)
    TFT_OUTPUT_VALUE = const(0x0c)
    MAX_SCREEN_BRIGHTNESS = const(0x0c)

    def __init__(self, i2c: machine.I2C, address: int):
        self._i2c = i2c
        self._address = address
        self._buffer = memoryview(bytearray(32))
        self._brightness = 0

    
    def _read_reg(self, reg:int) -> int:
        self._i2c.readfrom_mem_into(self._address, reg, self._buffer[0:1])
        return self._buffer[0]
    def _write_reg(self, reg:int, value:int) -> None:
        self._buffer[0] = value
        self._i2c.writeto_mem(self._address, reg, self._buffer)
    

    def screen_brightness(self, value:Optional[int] = None) -> int:
        if value is not None:
            if value < 0:
                value = 0
            elif value > AXP192.MAX_SCREEN_BRIGHTNESS:
                value = AXP192.MAX_SCREEN_BRIGHTNESS
            self._brightness = value
            self._write_reg(AXP192.REG_LDO2_LDO3_OUTPUT_VOLTAGE, AXP192.TFT_OUTPUT_VALUE | (value << 4))
        return self._brightness
    
    def enable_power_outputs(self, enable: bool) -> None:
        value = 0x4d if enable else 0x01
        self._write_reg(AXP192.REG_OUTPUT_ENABLE, value)
    
    def enable_coulomb_counter(self, enable: bool) -> None:
        value = 0x80 if enable else 0x00
        self._write_reg(AXP192.REG_COULOMB_COUNTER_CONTROL, value)
    
    def stop_coulomb_counter(self) -> None:
        self._write_reg(AXP192.REG_COULOMB_COUNTER_CONTROL, 0xc0)
        
    def clear_coulomb_counter(self) -> None:
        self._write_reg(AXP192.REG_COULOMB_COUNTER_CONTROL, 0xa0)
    
    def reset(self) -> None:
        self._write_reg(AXP192.REG_EXTEN_DCDC2_OUTPUT_CONFIG, 0xff)   # Enable all DC-DC2 outputs
        self.screen_brightness(AXP192.MAX_SCREEN_BRIGHTNESS)          # Initialize LDO2/LDO3 output.
        self._write_reg(AXP192.REG_ADC_ENABLE_1, 0xff)                # Enable all ADCs.
        self._write_reg(AXP192.REG_CHARGING_CONFIG, 0xc1)             # Enable charging, 190mA, 4.2V, 90%
        self.enable_coulomb_counter(True)                             # Enable coulomb counter (battery energy counter)
        self.enable_power_outputs(True)                               # Enable EXTEN, LDO3, LDO2, DC-DC1 output
        self._write_reg(AXP192.REG_PEK_CONFIG, 0x4c)                  # Shutdown 4s, Shutdown with button press longer than 4s, 
        self._write_reg(AXP192.REG_GPIO0_FUNCTION, 0x02)              # GPIO0 = Low Noise LDO, 
        self._write_reg(AXP192.REG_VBUS_IPSOUT_PATH_CONFIG, 0xe0)     # No use N_VBUSen, Limit Vbus voltage = 4.4V, Limit Vbus current = 500mA
        self._write_reg(AXP192.REG_VHTF_CHARGE_THRESHOLD, 0xfc)       # 
        self._write_reg(AXP192.REG_BACKUP_BATTERY_CHARGING, 0xa2)     # Enable charging backup battery, 3.0V, 200uA 

