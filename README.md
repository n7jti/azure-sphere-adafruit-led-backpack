# azure-sphere-adafruit-led-backpack
A port of the Arduino library for the [Adafruit LED Backpack](https://github.com/adafruit/Adafruit_LED_Backpack) to Azure Sphere that uses C++.  Note: Microsoft DOES NOT support C++ develpment on the Azure Sphere. Proceed at your own risk! 

This port of the Adafruit LED Backpack library is tested and works with the [SEEED Azure Sphere MT3620 Develpoment Kit](https://www.seeedstudio.com/Azure-Sphere-MT3620-Development-Kit-US-Version.html) and the [SEED MT3620 Mini Dev Board](https://www.seeedstudio.com/MT3620-Mini-Dev-Board-p-2919.html)

This is a library for the Adafruit LED Backpacks. Not every type of display has been tested.  However, at least one device from every section below has been tested, and there is at least one exapmle for each. 

Seven Segment Display

* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Blue](http://www.adafruit.com/products/881)
* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Green](http://www.adafruit.com/products/880)
* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Yellow](http://www.adafruit.com/products/879)
* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Red](http://www.adafruit.com/products/878)

Alphanumeric Display

* [Adafruit 0.54" Quad Alphanumeric FeatherWing Display - Red](https://www.adafruit.com/product/3130)
* [Adafruit 0.54" Quad Alphanumeric FeatherWing Display - White](https://www.adafruit.com/product/3127)
* [Adafruit 0.54" Quad Alphanumeric FeatherWing Display - Blue](https://www.adafruit.com/product/3128)
* [Adafruit 0.54" Quad Alphanumeric FeatherWing Display - Green](https://www.adafruit.com/product/3129)
* [Adafruit 0.54" Quad Alphanumeric FeatherWing Display - Yellow](https://www.adafruit.com/product/3131)
* [Adafruit 0.54" Quad Alphanumeric FeatherWing Display - Yellow/Green](https://www.adafruit.com/product/3132)

8x8 Matrix Display

* [Adafruit Small 1.2" 8x8 LED Matrix w/I2C Backpack - Red](https://www.adafruit.com/product/1049)
* [Adafruit Small 1.2" 8x8 LED Matrix w/I2C Backpack - Blue](https://www.adafruit.com/product/1052)
* [Adafruit Small 1.2" 8x8 LED Matrix w/I2C Backpack - Yellow](https://www.adafruit.com/product/1050)
* [Adafruit Small 1.2" 8x8 LED Matrix w/I2C Backpack - YellowGreen](https://www.adafruit.com/product/1051)
* [Adafruit Small 1.2" 8x8 LED Matrix w/I2C Backpack - Pure Green](https://www.adafruit.com/product/1632)

8x8 Bicolor Pixel Matrix

 * [Adafruit Bicolor LED Square Pixel Matrix with I2C Backpack](https://www.adafruit.com/product/902)

8x16 Matrix Display
* [16x8 1.2" LED Matrix + Backpack - Ultra Bright Square Green LEDs](https://www.adafruit.com/product/2042)
* [16x8 1.2" LED Matrix + Backpack - Ultra Bright Square Yellow LEDs](https://www.adafruit.com/product/2043)
* [16x8 1.2" LED Matrix + Backpack - Ultra Bright Square Blue LEDs](https://www.adafruit.com/product/2040)
* [16x8 1.2" LED Matrix + Backpack - Ultra Bright Square Amber LEDs](https://www.adafruit.com/product/2041)



These displays use I2C to communicate, 2 pins are required to 
interface (plus two more for power and ground). There are multiple selectable I2C addresses. For backpacks
with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
with 3 Address Select pins: 0x70 thru 0x77

Originally Written by Limor Fried/Ladyada for Adafruit Industries.

Ported to the Azure Sphere by Alan Ludwig

Unless otherwise noted, code is under the MIT license.  However, individual files may use a differet license as noted at the top of the file. 

MIT license, all text above must be included in any redistribution.
