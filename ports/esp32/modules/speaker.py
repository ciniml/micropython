import machine
import time

class Speaker:
    def __init__(self, pin:int = 25):
        self._pwm = machine.PWM(machine.Pin(pin, value=0), freq = 1, duty = 0)

    def tone(self, freq:int = 440, duration_ms:int = 100, volume:int = 10):
        self._pwm.init(freq = freq, duty = volume)
        time.sleep_ms(duration_ms)
        self._pwm.init(freq = 1, duty = 0)
