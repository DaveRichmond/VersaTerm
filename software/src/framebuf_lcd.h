#pragma once

#include "framebuf_driver.h"

class framebuf_lcd : public framebuf_driver {
private:
    uint8_t *charbuf = NULL;
    sSegm*   textSeg = NULL;
public:
    framebuf_lcd(uint8_t *databuf, uint8_t *rowattr);

    virtual void charmemset(uint32_t idx, uint8_t c, uint8_t a, uint8_t fg, uint8_t bg, size_t n);
    virtual void charmemmove(uint32_t toidx, uint32_t fromidx, size_t n);
    virtual uint8_t get_char(uint32_t idx);
    virtual void set_char(uint32_t idx, uint8_t c);
    virtual uint8_t get_attr(uint32_t idx);
    virtual void set_attr(uint32_t idx, uint8_t a);
    virtual void set_color(uint32_t char_index, uint8_t fg, uint8_t bg);
    virtual void get_color(uint32_t char_index, uint8_t *fg, uint8_t *bg);
    virtual void set_char_and_attr(uint32_t idx, uint32_t c);
    virtual uint32_t get_char_and_attr(uint32_t idx);
};