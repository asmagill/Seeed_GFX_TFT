Seeed_GFX_TFT
=============

This library allows the _Seeed TFT Touch Shield V1.0_ to be used with [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library).

If you have the _Seeed TFT Touch Shield V2.x_, see [Adafruit_ILI9341](https://github.com/adafruit/Adafruit_ILI9341).  I've had success using this library with the constructor `Adafruit_ILI9341(/* TFT_CS */ 5, /* TFT_DC */ 6)`.

### Notes

Requires [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) to provide drawing primitives and font support.

This library has been tested with the Arduino UNO and DFRobot's Bluno. Due to heavy use of port registers for pin manipulation, it is likely that this library will require modification if you wish to use it with a board that does not conform closely to the Uno's layout.

Portions based on code from [TFT_Touch_Shield_V1](https://github.com/Seeed-Studio/TFT_Touch_Shield_V1).

### Known Issues

* I'm not completely happy with the code handling rotation, especially in the `drawFastVLine` and `drawFastVLine` functions -- text  on subsequent lines may apear to bleed into the previous line.  I suspect this has to do with the pixel size of the display and scanning direction set by the `0x03` opcode; however changing this also changes the apparent origin of the display in ways I haven't deciphered yet.  This may be addressed in the future, or it may not -- the library meets my needs at present.

### References
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
* [TFT_Touch_Shield_V1](https://github.com/Seeed-Studio/TFT_Touch_Shield_V1)
* [ST7781R datasheet](http://wiki.seeedstudio.com/images/4/4e/ST7781R_datasheet.pdf)

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
