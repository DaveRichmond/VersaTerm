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

#include "global.h"
#include "framebuf_lcd.h"

extern "C"
{
#include "framebuf.h"
#include "font.h"
#include "config.h"
}

// defined in framebuf.c
extern int16_t framebuf_flash_counter;
extern uint8_t framebuf_flash_color;


void framebuf_lcd::charmemset(uint32_t idx, uint8_t c, uint8_t a, uint8_t fg, uint8_t bg, size_t n)
{
  uint32_t w = c + (a<<8) + (bg << 16) + (fg << 24);
  uint32_t *buf = (uint32_t *) (charbuf + idx*4);
  for(size_t i=0; i<n; i++) buf[i] = w;
}


void framebuf_lcd::charmemmove(uint32_t toidx, uint32_t fromidx, size_t n)
{
  memmove(charbuf+toidx*4, charbuf+fromidx*4, n*4);
}


void framebuf_lcd::set_char(uint32_t idx, uint8_t c)
{
  charbuf[idx*4] = c;
}


uint8_t framebuf_lcd::get_char(uint32_t idx)
{
  return charbuf[idx*4];
}


void framebuf_lcd::set_attr(uint32_t idx, uint8_t a)
{
  charbuf[idx*4+1] = a;
}


uint8_t framebuf_lcd::get_attr(uint32_t idx)
{
  return charbuf[idx*4 + 1];
}


void framebuf_lcd::set_color(uint32_t idx, uint8_t fg, uint8_t bg)
{
  charbuf[idx*4 + 2] = bg;
  charbuf[idx*4 + 3] = fg;
}


void framebuf_lcd::get_color(uint32_t idx, uint8_t *fg, uint8_t *bg)
{
  *bg = charbuf[idx*4 + 2];
  *fg = charbuf[idx*4 + 3];
}


void framebuf_lcd::set_char_and_attr(uint32_t idx, uint32_t c)
{
  ((uint32_t *) charbuf)[idx] = c;
}


uint32_t framebuf_lcd::get_char_and_attr(uint32_t idx)
{
  return ((uint32_t *) charbuf)[idx];
}


framebuf_lcd::framebuf_lcd(uint8_t *databuf, uint8_t *rowattr){
  charbuf = databuf;

}
