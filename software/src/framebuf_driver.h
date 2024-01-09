#pragma once

class framebuf_driver {
public:
    virtual void charmemset(uint32_t idx, uint8_t c, uint8_t a, uint8_t fg, uint8_t bg, size_t n) = 0;
    virtual void charmemmove(uint32_t toidx, uint32_t fromidx, size_t n) = 0;
    virtual uint8_t get_char(uint32_t idx) = 0;
    virtual void set_char(uint32_t idx, uint8_t c) = 0;
    virtual uint8_t get_attr(uint32_t idx) = 0;
    virtual void set_attr(uint32_t idx, uint8_t a) = 0;
    virtual void set_color(uint32_t char_index, uint8_t fg, uint8_t bg) = 0;
    virtual void get_color(uint32_t char_index, uint8_t *fg, uint8_t *bg) = 0;
    virtual void set_char_and_attr(uint32_t idx, uint32_t c) = 0;
    virtual uint32_t get_char_and_attr(uint32_t idx) = 0;
};