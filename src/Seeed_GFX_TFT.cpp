#include "Seeed_GFX_TFT.h"

Seeed_GFX_TFT::Seeed_GFX_TFT(void) : Adafruit_GFX(ST7781R_TFTWIDTH, ST7781R_TFTHEIGHT) {
}

void Seeed_GFX_TFT::begin(void) {
    TFT1_CS_OUTPUT ; TFT1_RD_OUTPUT ; TFT1_WR_OUTPUT ; TFT1_RS_OUTPUT ;
    all_pin_output() ; all_pin_low() ;
    delay(100) ;
    sendCommand(0x01) ; sendData(0x0100) ; // Driver Output Control             : the shift direction of outputs is from S720 to S1
    sendCommand(0x02) ; sendData(0x0700) ; // ??
    sendCommand(0x03) ; sendData(0x1030) ; // Entry Mode
    sendCommand(0x04) ; sendData(0x0000) ; // Resize Control                    : No resizing/no extra bytes per horizontal line
    sendCommand(0x08) ; sendData(0x0302) ; // Display Control 2                 : Front Porch 3 lines, Back Porch 2 lines
    sendCommand(0x0A) ; sendData(0x0000) ; // Display Control 4                 : No FMARK signal
    sendCommand(0x0C) ; sendData(0x0000) ; // RGB Display Interface Control 1   : Still picture, internal clock, 18bit RGB
    sendCommand(0x0D) ; sendData(0x0000) ; // Frame Marker Position             : FMARK at 0th line
    sendCommand(0x0F) ; sendData(0x0000) ; // RGB Display Interface Control 2   : VSPL & HSPL low active, Enable write on 0, input on DOTCLK positive edge
    delay(100) ;
    sendCommand(0x30) ; sendData(0x0000) ; // Gamma control  1                  : γfine Adjustment Register for Positive Polarity
    sendCommand(0x31) ; sendData(0x0405) ; // Gamma control  2                  : γfine Adjustment Register for Positive Polarity
    sendCommand(0x32) ; sendData(0x0203) ; // Gamma control  3                  : γfine Adjustment Register for Positive Polarity
    sendCommand(0x35) ; sendData(0x0004) ; // Gamma control  4                  : γgradient Adjustment Register for Positive Polarity
    sendCommand(0x36) ; sendData(0x0B07) ; // Gamma control  5                  : γamplitude Adjustment Register for Positive Polarity
    sendCommand(0x37) ; sendData(0x0000) ; // Gamma control  6                  : γfine Adjustment Register for Negative Polarity
    sendCommand(0x38) ; sendData(0x0405) ; // Gamma control  7                  : γfine Adjustment Register for Negative Polarity
    sendCommand(0x39) ; sendData(0x0203) ; // Gamma control  8                  : γfine Adjustment Register for Negative Polarity
    sendCommand(0x3c) ; sendData(0x0004) ; // Gamma control  9                  : γgradient Adjustment Register for Negative Polarity
    sendCommand(0x3d) ; sendData(0x0B07) ; // Gamma control 10                  : γamplitude Adjustment Register for Negative Polarity
    sendCommand(0x20) ; sendData(0x0000) ; // Horizontal DRAM Address Set
    sendCommand(0x21) ; sendData(0x0000) ; // Vertical DRAM Address Set
    sendCommand(0x50) ; sendData(0x0000) ; // Horizontal Address Start Position
    sendCommand(0x51) ; sendData(0x00ef) ; // Horizontal Address End Position
    sendCommand(0x52) ; sendData(0x0000) ; // Vertical Address Start Position
    sendCommand(0x53) ; sendData(0x013f) ; // Vertical Address End Position
    delay(100) ;
    sendCommand(0x60) ; sendData(0xa700) ; // Driver Output Control 2           : the scan direction is from G320 to G1, 320 lines, start scan at G320
    sendCommand(0x61) ; sendData(0x0001) ; // Vertical Scroll Control           : Fixed, Greyscale Inversion, NDL 0
    sendCommand(0x90) ; sendData(0x003A) ; // Panel Interface Control 1         : Clock Division Ratio 1, 58 clocks
    sendCommand(0x95) ; sendData(0x021E) ; // Panel Interface Control 2         : division ratio of DOTCLK when operation is synchronized with RGB interface signals = 1/8
    sendCommand(0x80) ; sendData(0x0000) ; // Partial Image 1 Display Position
    sendCommand(0x81) ; sendData(0x0000) ; // Partial Image 1 Area (Start Line)
    sendCommand(0x82) ; sendData(0x0000) ; // Partial Image 1 Area (End Line)
    sendCommand(0x83) ; sendData(0x0000) ; // Partial Image 2 Display Position
    sendCommand(0x84) ; sendData(0x0000) ; // Partial Image 2 Area (Start Line)
    sendCommand(0x85) ; sendData(0x0000) ; // Partial Image 2 Area (End Line)
    sendCommand(0xFF) ; sendData(0x0001) ; // NVM Command Enable (On)           : enable DFh function
    sendCommand(0xB0) ; sendData(0x140D) ; // Power Control 2                   : VCOM -0.925, VGL -7.5, VGH 3*AVDD
    sendCommand(0xFF) ; sendData(0x0000) ; // NVM Command Enable (Off)          : disable DFh function
    delay(100) ;
    sendCommand(0x07) ; sendData(0x0133) ; // Display Control 1                 : Partial images disabled, base image displayed on the screen, Normal display, halt grayscale amplifiers to display 8-color, Base Image display lit
    delay(50) ;
//    exitStandBy() -- the next three lines; not sure why it was separate fn in the original library since there was no enterStandby
    sendCommand(0x10) ; sendData(0x14E0) ; // Power Control 1                   : SAP Source driver enabled, Power supply enable, Source and Gamme driver 0.25, no sleep or standby
    delay(100) ;
    sendCommand(0x07) ; sendData(0x0133) ; // Display Control 1                 : Partial images disabled, base image displayed on the screen, Normal display, halt grayscale amplifiers to display 8-color, Base Image display lit

    fillScreen(ST7781R_BLACK) ;
}

void Seeed_GFX_TFT::fillScreen(uint16_t color) {
    setXY(0, 0) ;
    for (uint16_t i = 0 ; i < 38400 ; i++) {
        sendData(color) ;
        sendData(color) ;
    }
}

void Seeed_GFX_TFT::invertDisplay(bool i) {
    sendCommand(0x61) ; sendData(i ? 0x0000 : 0x0001) ;
}

void Seeed_GFX_TFT::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if((x < 0) || (y < 0) || (x >= _width) || (y >= _height)) return ;

    int16_t t ;
    switch(rotation) {
        case 1:
            t = x ;
            x = WIDTH - 1 - y ;
            y = t ;
            break ;
        case 2:
            x = WIDTH  - 1 - x ;
            y = HEIGHT - 1 - y ;
            break;
        case 3:
            t = x ;
            x = y ;
            y = HEIGHT - 1 - t ;
            break;
    }

    setXY(x, y) ;
    sendData(color) ;
}

void Seeed_GFX_TFT::drawFastHLine(int16_t x, int16_t y, int16_t length, uint16_t color) {
    if ((y < 0) || (y >= _height)) return ; // it's off screen
    if (length < 0) {                       // if length is negative, make it positive and move end point (i.e. reverse)
        length *= -1 ;
        x = x - length ;
    }
    if (x >= _width) return ;               // it's off screen
    if (x < 0) length = length + x ;        // if x is negative, remove it from length (it's off screen)
    x = constrain(x, 0, _width  - 1) ;

    int16_t t ;
    switch(rotation) {
        case 1:
            t = x ;
            x = WIDTH - 1 - y ;
            y = t ;
            break ;
        case 2:
            x = WIDTH  - 1 - x - length ;
            y = HEIGHT - 1 - y ;
            break;
        case 3:
            t = x ;
            x = y - length ;
            y = HEIGHT - 1 - t ;
            break;
    }

    setXY(x, y) ;
    sendCommand(0x03) ; sendData((rotation % 2) ? 0x1038 : 0x1030) ; sendCommand(0x22) ;
    if (length + x > (_width - 1)) length = (_width - 1) - x;
    for (int16_t i = 0 ; i < length ; i++) sendData(color) ;
}

void Seeed_GFX_TFT::drawFastVLine(int16_t x, int16_t y, int16_t length, uint16_t color) {
    if ((x < 0) || (x >= _width)) return ; // it's off screen
    if (length < 0) {                      // if length is negative, make it positive and move end point (i.e. reverse)
        length *= -1 ;
        y = y - length ;
    }
    if (y >= _height) return ;             // it's off screen
    if (y < 0) length = length + y ;       // if y is negative, remove it from length (it's off screen)
    y = constrain(y, 0, _height - 1) ;

    int16_t t ;
    switch(rotation) {
        case 1:
            t = x ;
            x = WIDTH - 1 - y ;
            y = t ;
            break ;
        case 2:
            x = WIDTH  - 1 - x ;
            y = HEIGHT - 1 - y - length ;
            break;
        case 3:
            t = x ;
            x = y ;
            y = HEIGHT - 1 - t - length ;
            break;
    }

    setXY(x, y) ;
    sendCommand(0x03) ; sendData((rotation % 2) ? 0x1030 : 0x1038) ; sendCommand(0x22) ;
    if (length + y > (_height - 1)) length = (_height - 1) - y ;
    for (int16_t i = 0 ; i < length ; i++) sendData(color) ;
}

uint16_t Seeed_GFX_TFT::color565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3);
}

#pragma mark - Private Methods

void Seeed_GFX_TFT::setXY(int16_t x, int16_t y) {
    sendCommand(0x20) ; //X // Horizontal DRAM Address Set
    sendData((uint16_t)x) ;
    sendCommand(0x21) ; //Y // Vertical DRAM Address Set
    sendData((uint16_t)y) ;
    sendCommand(0x22) ;     // Write data to DRAM
}

void Seeed_GFX_TFT::all_pin_input(void) {
    DDRD &=~ 0xfc ;
    DDRB &=~ 0x03 ;
}

void Seeed_GFX_TFT::all_pin_output(void) {
    DDRD |= 0xfc ;
    DDRB |= 0x03 ;
}

void Seeed_GFX_TFT::all_pin_low(void) {
    PORTD &=~ 0xfc ;
    PORTB &=~ 0x03 ;
}

void Seeed_GFX_TFT::pushData(uint8_t data) {
    all_pin_low() ;
    PORTD |= (data << 2) ;
    PORTB |= (data >> 6) ;
}

void Seeed_GFX_TFT::sendCommand(uint16_t command) {
    uint8_t command1 = (command >> 8) & 0xff ;
    uint8_t command2 = command & 0xff ;
    TFT1_CS_LOW ;  TFT1_RS_LOW ; TFT1_RD_HIGH ;
    TFT1_WR_HIGH ; TFT1_WR_LOW ; pushData(command1) ;
    TFT1_WR_HIGH ; TFT1_WR_LOW ; pushData(command2) ;
    TFT1_WR_HIGH ; TFT1_CS_HIGH ;
}

void Seeed_GFX_TFT::sendData(uint16_t data) {
    uint8_t data1 = (data >> 8) & 0xff ;
    uint8_t data2 = data & 0xff ;
    TFT1_CS_LOW ;  TFT1_RS_HIGH ; TFT1_RD_HIGH ;
                   TFT1_WR_LOW ;  pushData(data1) ;
    TFT1_WR_HIGH ; TFT1_WR_LOW ;  pushData(data2) ;
    TFT1_WR_HIGH ; TFT1_CS_HIGH ;
}
