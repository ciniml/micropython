
#define LGFX_AUTODETECT
#include <LovyanGFX.hpp>

extern "C" {
#include "lgfx-c.h"
}

static LGFX lcd_default;

static LGFX& toLGFX(LGFX_LCD_t lcd) {
    return *reinterpret_cast<LGFX*>(lcd);
}

LGFX_LCD_t lgfx_get_default_lcd() {
    return reinterpret_cast<LGFX_LCD_t>(&lcd_default);
}

void lgfx_init(LGFX_LCD_t lcd) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.init();
}
void lgfx_setRotation(LGFX_LCD_t lcd, int rotation) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setRotation(rotation);
}
void lgfx_setBrightness(LGFX_LCD_t lcd, uint8_t brightness) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setBrightness(brightness);
}

void lgfx_fillRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillRect(x, y, w, h, color);
}
void lgfx_drawRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawRect(x, y, w, h, color);
}
void lgfx_drawRoundRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawRoundRect(x, y, w, h, r, color);
}
void lgfx_fillRoundRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillRoundRect(x, y, w, h, r, color);
}
void lgfx_drawCircle(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawCircle(x, y, r, color);
}
void lgfx_fillCircle(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillCircle(x, y, r, color);
}
void lgfx_drawEllipse(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t rx, int32_t ry, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawEllipse(x, y, rx, ry, color);
}
void lgfx_fillEllipse(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t rx, int32_t ry, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillEllipse(x, y, rx, ry, color);
}
void lgfx_drawLine(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawLine(x0, y0, x1, y1, color);
}
void lgfx_drawTriangle(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawTriangle(x0, y0, x1, y1, x2, y2, color);
}
void lgfx_fillTriangle(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillTriangle(x0, y0, x1, y1, x2, y2, color);
}
void lgfx_drawBezier(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawBezier(x0, y0, x1, y1, x2, y2, color);
}
void lgfx_drawBezierHelper(LGFX_LCD_t lcd, int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawBezierHelper(x0, y0, x1, y1, x2, y2, color);
}
void lgfx_drawArc(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r0, int32_t r1, float angle0, float angle1, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawArc(x, y, r0, r1, angle0, angle1, color);
}
void lgfx_fillArc(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t r0, int32_t r1, float angle0, float angle1, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillArc(x, y, r0, r1, angle0, angle1, color);
}

void lgfx_paint(LGFX_LCD_t lcd, int32_t x, int32_t y, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.paint(x, y, color);
}
void lgfx_floodFill(LGFX_LCD_t lcd, int32_t x, int32_t y, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.floodFill(x, y, color);
}

void lgfx_clear(LGFX_LCD_t lcd, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.clear(color);
}
void lgfx_fillScreen(LGFX_LCD_t lcd, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.fillScreen(color);
}

LCD_Color_t lgfx_color332(uint8_t r, uint8_t g, uint8_t b) {
    return LGFX::color332(r, g, b);
}
LCD_Color_t lgfx_color565(uint8_t r, uint8_t g, uint8_t b) {
    return LGFX::color565(r, g, b);
}
LCD_Color_t lgfx_color888(uint8_t r, uint8_t g, uint8_t b) {
    return LGFX::color888(r, g, b);
}
LCD_Color_t lgfx_swap565(uint8_t r, uint8_t g, uint8_t b) {
    return LGFX::swap565(r, g, b);
}
LCD_Color_t lgfx_swap888(uint8_t r, uint8_t g, uint8_t b) {
    return LGFX::swap888(r, g, b);
}

void lgfx_setClipRect(LGFX_LCD_t lcd, int32_t x, int32_t y, int32_t w, int32_t h) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setClipRect(x, y, w, h);
}
void lgfx_clearClipRect(LGFX_LCD_t lcd) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.clearClipRect();
}

void lgfx_drawBitmap(LGFX_LCD_t lcd, int32_t x, int32_t y, const uint8_t* bitmap, int32_t w, int32_t h, LCD_Color_t fgColor, LCD_Color_t bgColor) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.drawBitmap(x, y, bitmap, w, h, fgColor, bgColor);
}

void lgfx_drawString(LGFX_LCD_t lcd, const char* string, int32_t x, int32_t y, uint8_t font) {
    auto& lcd_ = toLGFX(lcd);
    if( font == 0xff ) {
        lcd_.drawString(string, x, y);
    }
    else {
        lcd_.drawString(string, x, y, font);
    }
}

void lgfx_setColor(LGFX_LCD_t lcd, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setColor(color);
}
void lgfx_setTextFont(LGFX_LCD_t lcd, uint8_t font) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setTextFont(font);
}
void lgfx_setTextColor(LGFX_LCD_t lcd, LCD_Color_t color) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setTextColor(color);
}
void lgfx_setTextSize(LGFX_LCD_t lcd, float sx, float sy) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setTextSize(sx, sy);
}
void lgfx_setTextDatum(LGFX_LCD_t lcd, uint8_t datum) {
    auto& lcd_ = toLGFX(lcd);
    lcd_.setTextDatum(static_cast<textdatum_t>(datum));
}