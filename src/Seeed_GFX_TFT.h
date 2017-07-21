/*

    This library enables the 2.8" TFT Touch Shield V1.0 to be used with the
    Adafruit GFX library (https://github.com/adafruit/Adafruit-GFX-Library)

    Portions based on code at https://github.com/Seeed-Studio/TFT_Touch_Shield_V1

    The MIT License (MIT)

    Copyright (c) 2017 Aaron Magill

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

*/
#ifndef _SEED_GFX_TFT_H
#define _SEED_GFX_TFT_H

#include "Arduino.h"
#include "Adafruit_GFX.h"

#define ST7781R_TFTWIDTH   240
#define ST7781R_TFTHEIGHT  320

// Some Colors
#define ST7781R_BRIGHT_RED  0xf810
#define ST7781R_GRAY1       0x8410
#define ST7781R_GRAY2       0x4208

#define ST7781R_BLACK       0x0000
#define ST7781R_NAVY        0x000F
#define ST7781R_DARKGREEN   0x03E0
#define ST7781R_DARKCYAN    0x03EF
#define ST7781R_MAROON      0x7800
#define ST7781R_PURPLE      0x780F
#define ST7781R_OLIVE       0x7BE0
#define ST7781R_LIGHTGREY   0xC618
#define ST7781R_DARKGREY    0x7BEF
#define ST7781R_BLUE        0x001F
#define ST7781R_GREEN       0x07E0
#define ST7781R_CYAN        0x07FF
#define ST7781R_RED         0xF800
#define ST7781R_MAGENTA     0xF81F
#define ST7781R_YELLOW      0xFFE0
#define ST7781R_WHITE       0xFFFF
#define ST7781R_ORANGE      0xFD20
#define ST7781R_GREENYELLOW 0xAFE5
#define ST7781R_PINK        0xF81F

// v1 Constants

//========================================
#define TFT1_DDR_CS      DDRB
#define TFT1_PORT_CS     PORTB
#define TFT1_CS_BIT      0x04
#define TFT1_CS_OUTPUT   {TFT1_DDR_CS|=TFT1_CS_BIT;}
#define TFT1_CS_HIGH     {TFT1_PORT_CS|=TFT1_CS_BIT;}
#define TFT1_CS_LOW      {TFT1_PORT_CS&=~TFT1_CS_BIT;}

//-----------------------------------------

#define TFT1_DDR_RS      DDRB
#define TFT1_PORT_RS     PORTB
#define TFT1_RS_BIT      0x08
#define TFT1_RS_OUTPUT   {TFT1_DDR_RS|=TFT1_RS_BIT;}
#define TFT1_RS_HIGH     {TFT1_PORT_RS|=TFT1_RS_BIT;}
#define TFT1_RS_LOW      {TFT1_PORT_RS&=~TFT1_RS_BIT;}

//-----------------------------------------

#define TFT1_DDR_WR      DDRB
#define TFT1_PORT_WR     PORTB
#define TFT1_WR_BIT      0x10
#define TFT1_WR_OUTPUT   {TFT1_DDR_WR|=TFT1_WR_BIT;}
#define TFT1_WR_HIGH     {TFT1_PORT_WR|=TFT1_WR_BIT;}
#define TFT1_WR_LOW      {TFT1_PORT_WR&=~TFT1_WR_BIT;}
#define TFT1_WR_RISING   {TFT1_PORT_WR|=TFT1_WR_BIT;TFT1_PORT_WR&=~TFT1_WR_BIT;}

//-----------------------------------------

#define TFT1_DDR_RD      DDRB
#define TFT1_PORT_RD     PORTB
#define TFT1_RD_BIT      0x20
#define TFT1_RD_OUTPUT   {TFT1_DDR_RD|=TFT1_RD_BIT;}
#define TFT1_RD_HIGH     {TFT1_PORT_RD|=TFT1_RD_BIT;}
#define TFT1_RD_LOW      {TFT1_PORT_RD&=~TFT1_RD_BIT;}
#define TFT1_RD_RISING   {TFT1_PORT_RD|=TFT1_RD_BIT;TFT1_PORT_RD&=~TFT1_RD_BIT;}
//========================================


class Seeed_GFX_TFT : public Adafruit_GFX {
    public:

        Seeed_GFX_TFT() ; // Constructor

        void      begin(void) ;

        // This MUST be defined by the subclass:
        void      drawPixel(int16_t x, int16_t y, uint16_t color) ;

        // TRANSACTION API / CORE DRAW API
        // These MAY be overridden by the subclass to provide device-specific
        // optimized code.  Otherwise 'generic' versions are used.
        // void      startWrite(void) ;
        // void      writePixel(int16_t x, int16_t y, uint16_t color) ;
        // void      writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) ;
        // void      writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) ;
        // void      writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) ;
        // void      writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) ;
        // void      endWrite(void) ;

        // CONTROL API
        // These MAY be overridden by the subclass to provide device-specific
        // optimized code.  Otherwise 'generic' versions are used.
        // void      setRotation(uint8_t r) ;
        void      invertDisplay(bool i) ;

        // BASIC DRAW API
        // These MAY be overridden by the subclass to provide device-specific
        // optimized code.  Otherwise 'generic' versions are used.

        // It's good to implement those, even if using transaction API
        void      drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) ;
        void      drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) ;
        // void      fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) ;
        void      fillScreen(uint16_t color) ;
        // Optional and probably not necessary to change
        // void      drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) ;
        // void      drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) ;

        // Other additions

        // From Adafruit_ILI9341 -- the example file uses it and it seems useful
        uint16_t  color565(uint8_t r, uint8_t g, uint8_t b) ;

    private:
        void  sendCommand(uint16_t index) ;
        void  sendData(uint16_t data) ;
        void  pushData(uint8_t data) ;
        void  all_pin_input(void) ;
        void  all_pin_output(void) ;
        void  all_pin_low(void) ;
        void  setXY(int16_t poX, int16_t poY) ;
        void  reallyDrawHorizontalLine(int16_t x, int16_t y, int16_t length, uint16_t color) ;
        void  reallyDrawVerticalLine(int16_t x, int16_t y, int16_t length, uint16_t color) ;

} ;

#endif
