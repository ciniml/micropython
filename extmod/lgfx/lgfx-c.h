#ifndef LGFX_C_H__
#define LGFX_C_H__

#include <stdint.h>

struct LGFX_LCD;
typedef struct LGFX_LCD* LGFX_LCD_t;
typedef uint16_t LCD_Color_t;


LGFX_LCD_t lgfx_get_default_lcd();

extern void lgfx_init(LGFX_LCD_t lcd);
extern void lgfx_setRotation(LGFX_LCD_t lcd, int rotation);
extern void lgfx_setBrightness(LGFX_LCD_t lcd, uint8_t brightness);

extern void lgfx_fillRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, LCD_Color_t color);
extern void lgfx_drawRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, LCD_Color_t color);
extern void lgfx_drawRoundRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, LCD_Color_t color);
extern void lgfx_fillRoundRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, LCD_Color_t color);
extern void lgfx_drawCircle(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r, LCD_Color_t color);
extern void lgfx_fillCircle(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r, LCD_Color_t color);
extern void lgfx_drawEllipse(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t rx, int32_t ry, LCD_Color_t color);
extern void lgfx_fillEllipse(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t rx, int32_t ry, LCD_Color_t color);
extern void lgfx_drawLine(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, LCD_Color_t color) ;
extern void lgfx_drawTriangle(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color);
extern void lgfx_fillTriangle(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color);
extern void lgfx_drawBezier(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color);
extern void lgfx_drawBezierHelper(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color);
extern void lgfx_drawArc(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r0, int32_t r1, float angle0, float angle1, LCD_Color_t color);
extern void lgfx_fillArc(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r0, int32_t r1, float angle0, float angle1, LCD_Color_t color);

extern void lgfx_paint(LGFX_LCD_t lcd, int32_t x, int32_t y, LCD_Color_t color);
extern void lgfx_floodFill(LGFX_LCD_t lcd, int32_t x, int32_t y, LCD_Color_t color);

extern void lgfx_clear(LGFX_LCD_t lcd, LCD_Color_t color);
extern void lgfx_fillScreen(LGFX_LCD_t lcd, LCD_Color_t color);

extern LCD_Color_t lgfx_color332(uint8_t r, uint8_t g, uint8_t b);
extern LCD_Color_t lgfx_color565(uint8_t r, uint8_t g, uint8_t b);
extern LCD_Color_t lgfx_color888(uint8_t r, uint8_t g, uint8_t b);
extern LCD_Color_t lgfx_swap565(uint8_t r, uint8_t g, uint8_t b);
extern LCD_Color_t lgfx_swap888(uint8_t r, uint8_t g, uint8_t b);

extern void lgfx_setClipRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h);
extern void lgfx_clearClipRect(LGFX_LCD_t lcd);

extern void lgfx_drawBitmap(LGFX_LCD_t lcd, int32_t x, int32_t y, const uint8_t* bitmap, int32_t w, int32_t h, LCD_Color_t fgColor, LCD_Color_t bgColor);

extern void lgfx_drawString(LGFX_LCD_t lcd, const char* string, int32_t x, int32_t y, uint8_t font);

extern void lgfx_setColor(LGFX_LCD_t lcd, LCD_Color_t color);
extern void lgfx_setTextFont(LGFX_LCD_t lcd, uint8_t font);
extern void lgfx_setTextColor(LGFX_LCD_t lcd, LCD_Color_t color);
extern void lgfx_setTextSize(LGFX_LCD_t lcd, float sx, float sy);
extern void lgfx_setTextDatum(LGFX_LCD_t lcd, uint8_t datum);

#endif //LGFX_C_H__