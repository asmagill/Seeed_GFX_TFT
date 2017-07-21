#include "Adafruit_GFX.h"
#include "Seeed_GFX_TFT.h"

Seeed_GFX_TFT tft = Seeed_GFX_TFT() ;


void setup() {
  Serial.begin(115200);
  Serial.println("ST7781R Rotation Test!");
  tft.begin();
}

void loop() {
    static uint8_t currentRotation = 0 ;
    tft.setRotation(currentRotation) ;
    tft.fillScreen(ST7781R_BLACK) ;
    tft.setTextColor(ST7781R_WHITE, ST7781R_BLACK) ;
    tft.setTextWrap(true) ;

    tft.setCursor(0, 0) ;
    tft.setTextSize(2) ;
    tft.print("R") ;
    tft.setTextSize(1) ;
    tft.print("otation") ;
    tft.setTextSize(2) ;
    tft.print("T") ;
    tft.setTextSize(1) ;
    tft.print("est") ;

    int16_t H = tft.height() ;
    int16_t W = tft.width() ;

    tft.fillRoundRect(25, 25, W - 50, H - 50, 15, ST7781R_LIGHTGREY) ;

    for(int16_t i = 35 ; i <= W - 35 ; i = i + 10) {
        tft.drawLine(i, 35, i, H - 35, ST7781R_BLUE) ;
        for(int16_t j = 35 ; j <= H - 35 ; j = j + 10) {
            tft.drawLine(35, j, W - 35, j, ST7781R_BLUE) ;
        }
    }

    tft.drawLine(55, 55, W - 55, H - 55, ST7781R_RED) ;
    tft.drawLine(W - 55, 55, 55, H - 55, ST7781R_RED) ;

    tft.fillCircle(    55,     55, 15, ST7781R_CYAN) ;
    tft.fillCircle(W - 55,     55, 15, ST7781R_YELLOW) ;
    tft.fillCircle(    55, H - 55, 15, ST7781R_MAGENTA) ;
    tft.fillCircle(W - 55, H - 55, 15, ST7781R_BLACK) ;

    tft.fillTriangle(W / 2, (H / 2) - 50, (W / 2) + 50, (H / 2) + 25, (W / 2) - 50, (H / 2) + 25, ST7781R_GREENYELLOW) ;
    tft.fillTriangle(W / 2, (H / 2) + 50, (W / 2) + 50, (H / 2) - 25, (W / 2) - 50, (H / 2) - 25, ST7781R_GREENYELLOW) ;

    delay(3000) ;
    currentRotation = (currentRotation + 1) % 4 ;
}
