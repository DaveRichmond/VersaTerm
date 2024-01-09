// -----------------------------------------------------------------------------
// VersaTerm - A versatile serial terminal
// Copyright (C) 2022 David Hansel
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
// -----------------------------------------------------------------------------

#ifndef FRAMEBUF_VGA_H
#define FRAMEBUF_VGA_H

#include "global.h"
#include "framebuf_driver.h"

class framebuf_vga : public framebuf_driver {    
public:
    uint8_t *charbuf = NULL;
    sSegm*   textSeg = NULL;
    framebuf_vga(uint8_t *databuf, uint8_t *rowattr);

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

#endif
