Seeed_GFX_TFT
=============

This library allows the _Seeed TFT Touch Shield V1.0_ to be used with [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library).

If you have the _Seeed TFT Touch Shield V2.x_, see [Adafruit_ILI9341](https://github.com/adafruit/Adafruit_ILI9341).  I've had success using this library with the constructor `Adafruit_ILI9341(/* TFT_CS */ 5, /* TFT_DC */ 6)`.

### Notes

Requires [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) to provide drawing primitives and font support.

This library has been tested with the Arduino UNO and DFRobot's Bluno. Due to heavy use of port registers for pin manipulation, it is likely that this library will require modification if you wish to use it with a board that does not conform closely to the Uno's layout.

Portions based on code from [TFT_Touch_Shield_V1](https://github.com/Seeed-Studio/TFT_Touch_Shield_V1).

### Known Issues / Limitations

* Filling rectangles is slow; may be able to speed up some with a better understanding of the ST7781R opcodes then I have at present.
* No way to turn off the backlight; I suspect this may be a limitation of the hardware as initial testing of the sleep and suspend modes only clears the display.
* Have not tested bitmap images; given that this particular shield does not leave enough available pins for adding an SD Card shield, this may be moot due to memory limitations.
* May add support for Leonardo and/or Arduino 101

### References
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
* [TFT_Touch_Shield_V1](https://github.com/Seeed-Studio/TFT_Touch_Shield_V1)
* [ST7781R datasheet (pdf)](http://wiki.seeedstudio.com/images/4/4e/ST7781R_datasheet.pdf)

### License

> The MIT License (MIT)
>
> Copyright (c) 2017 Aaron Magill
>
> Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
