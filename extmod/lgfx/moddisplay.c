#include "py/mphal.h"
#include "py/runtime.h"

#include "lgfx-c.h"

typedef struct _mp_obj_display_t {
    mp_obj_base_t base;

    LGFX_LCD_t lcd;
} mp_obj_display_t;

STATIC mp_obj_t display_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    
    mp_obj_display_t* o = m_new_obj(mp_obj_display_t);
    o->base.type = type;
    o->lcd = lgfx_get_default_lcd();

    return MP_OBJ_FROM_PTR(o);
}

STATIC mp_obj_t display_init(mp_obj_t self_in)
{
    mp_obj_display_t* self = MP_OBJ_TO_PTR(self_in);
    lgfx_init(self->lcd);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(display_init_obj, display_init);

STATIC mp_obj_t display_set_rotation(mp_obj_t self_in, mp_obj_t rotation)
{
    mp_obj_display_t* self = MP_OBJ_TO_PTR(self_in);
    mp_int_t rotation_int = mp_obj_get_int_truncated(rotation);
    lgfx_setRotation(self->lcd, rotation_int);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(display_set_rotation_obj, display_set_rotation);


STATIC mp_obj_t display_set_text_font(mp_obj_t self_in, mp_obj_t font_number)
{
    mp_obj_display_t* self = MP_OBJ_TO_PTR(self_in);
    mp_int_t font_number_int = mp_obj_get_int_truncated(font_number);
    lgfx_setTextFont(self->lcd, font_number_int);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(display_set_text_font_obj, display_set_text_font);

STATIC mp_obj_t display_draw_string(size_t nargs, mp_obj_t const* args)
{
    mp_obj_display_t* self = MP_OBJ_TO_PTR(args[0]);
    const char* string_s = mp_obj_str_get_str(args[1]);
    mp_int_t x_int = mp_obj_get_int(args[2]);
    mp_int_t y_int = mp_obj_get_int(args[3]);
    if( nargs == 4 ) {
        lgfx_drawString(self->lcd, string_s, x_int, y_int, 0xff);
    }
    else {
        mp_int_t font_int = mp_obj_get_int(args[4]);
        lgfx_drawString(self->lcd, string_s, x_int, y_int, font_int);
    }

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(display_draw_string_obj, 4, 5, display_draw_string);

STATIC mp_obj_t display_set_text_datum(mp_obj_t self_in, mp_obj_t datum)
{
    mp_obj_display_t* self = MP_OBJ_TO_PTR(self_in);
    mp_int_t datum_int = mp_obj_get_int_truncated(datum);
    lgfx_setTextDatum(self->lcd, (uint8_t)datum_int);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(display_set_text_datum_obj, display_set_text_datum);

STATIC mp_obj_t display_fillscreen(mp_obj_t self_in, mp_obj_t color)
{
    mp_obj_display_t* self = MP_OBJ_TO_PTR(self_in);
    mp_int_t color_int = mp_obj_get_int_truncated(color);
    lgfx_fillScreen(self->lcd, color_int);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(display_fillscreen_obj, display_fillscreen);

STATIC const mp_rom_map_elem_t display_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&display_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_fillscreen), MP_ROM_PTR(&display_fillscreen_obj) },
    { MP_ROM_QSTR(MP_QSTR_set_rotation), MP_ROM_PTR(&display_set_rotation_obj) },
    { MP_ROM_QSTR(MP_QSTR_draw_string), MP_ROM_PTR(&display_draw_string_obj) },
    { MP_ROM_QSTR(MP_QSTR_set_text_datum), MP_ROM_PTR(&display_set_text_datum_obj) },
    { MP_ROM_QSTR(MP_QSTR_set_text_font), MP_ROM_PTR(&display_set_text_font_obj) },

};
STATIC MP_DEFINE_CONST_DICT(display_locals_dict, display_locals_dict_table);

STATIC const mp_obj_type_t display_type = {
    .base = { &mp_type_type },
    .name = MP_QSTR_display,
    .make_new = display_make_new,
    .locals_dict = (mp_obj_dict_t*)&display_locals_dict,
};

STATIC const mp_rom_map_elem_t module_display_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_display) },
    { MP_ROM_QSTR(MP_QSTR_display), MP_ROM_PTR(&display_type) },
};
STATIC MP_DEFINE_CONST_DICT(module_display_dict, module_display_dict_table);

const mp_obj_module_t mp_module_display = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&module_display_dict,
};