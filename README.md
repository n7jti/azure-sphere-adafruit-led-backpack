# azure-sphere-adafruit-led-backpack
A port of the Arduino library for the [Adafruit LED Backpack](https://github.com/adafruit/Adafruit_LED_Backpack) to Azure Sphere.

This port of the Adafruit LED Backpack library is tested and works with the [SEEED Azure Sphere MT3620 Develpoment Kit](https://www.seeedstudio.com/Azure-Sphere-MT3620-Development-Kit-US-Version.html) and the [SEED MT3620 Mini Dev Board](https://www.seeedstudio.com/MT3620-Mini-Dev-Board-p-2919.html)

This is a library for the Adafruit LED Backpacks
This library works with the Adafruit 7-Segment LED Backpacks, but will be expanded over time to support more displays. As those displays are supported, links to the corresponding adafruit products will be included here. 

* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Blue](http://www.adafruit.com/products/881)
* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Green](http://www.adafruit.com/products/880)
* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Yellow](http://www.adafruit.com/products/879)
* [Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack - Red](http://www.adafruit.com/products/878)

These displays use I2C to communicate, 2 pins are required to 
interface. There are multiple selectable I2C addresses. For backpacks
with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
with 3 Address Select pins: 0x70 thru 0x77

Originally Written by Limor Fried/Ladyada for Adafruit Industries.
Ported to the Azure Sphere by Alan Ludwig
MIT license, all text above must be included in any redistribution.