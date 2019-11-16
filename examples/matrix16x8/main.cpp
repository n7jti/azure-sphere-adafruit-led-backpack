/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit 16x8 LED Matrix backpacks 
  ----> http://www.adafruit.com/products/2035
  ----> http://www.adafruit.com/products/2036
  ----> http://www.adafruit.com/products/2037
  ----> http://www.adafruit.com/products/2038
  ----> http://www.adafruit.com/products/2039
  ----> http://www.adafruit.com/products/2040
  ----> http://www.adafruit.com/products/2041
  ----> http://www.adafruit.com/products/2042
  ----> http://www.adafruit.com/products/2043
  ----> http://www.adafruit.com/products/2044
  ----> http://www.adafruit.com/products/2052

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <errno.h>
#include <string.h>
#include <time.h>
#include <applibs/log.h>

#include "../../Adafruit_LEDBackpack.h"

extern "C" void __cxa_pure_virtual() { while (1); }

using adafruit::ledbackpack::Adafruit_8x16matrix;

Adafruit_8x16matrix matrix = Adafruit_8x16matrix(0);

static const uint8_t 
  smile_bmp[] =
  { 0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b01000010,
    0b00111100 },
  neutral_bmp[] =
  { 0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10111101,
    0b10000001,
    0b01000010,
    0b00111100 },
  frown_bmp[] =
  { 0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10011001,
    0b10100101,
    0b01000010,
    0b00111100 };

int main(void)
{
    Log_Debug("Starting 16x8 LED Matrix Test...\n");
	
    Adafruit_8x16matrix matrix(0); 

    const struct timespec sleep500 = {0, 500000000};
	const struct timespec sleep100 = {0, 100000000};
	matrix.begin(0x70);

    while (true) {
		matrix.clear();
		matrix.drawBitmap(0, 0, smile_bmp, 8, 8, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();
		nanosleep(&sleep500, nullptr);
		
		matrix.clear();
		matrix.drawBitmap(0, 8, neutral_bmp, 8, 8, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();
		nanosleep(&sleep500, nullptr);

		matrix.clear();
		matrix.drawBitmap(0, 0, frown_bmp, 8, 8, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();
		nanosleep(&sleep500, nullptr);

		matrix.clear();      // clear display
		matrix.drawPixel(0, 0, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();  // write the changes we just made to the display
		nanosleep(&sleep500, nullptr);

		matrix.clear();
		matrix.drawLine(0,0, 7,15, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();  // write the changes we just made to the display
		nanosleep(&sleep500, nullptr);

		matrix.clear();
		matrix.drawRect(0,0, 8,16, adafruit::ledbackpack::LED_ON);
		matrix.fillRect(2,2, 4,12, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();  // write the changes we just made to the display
		nanosleep(&sleep500, nullptr);

		matrix.clear();
		matrix.drawCircle(3,8, 3, adafruit::ledbackpack::LED_ON);
		matrix.writeDisplay();  // write the changes we just made to the display
		nanosleep(&sleep500, nullptr);

		matrix.setTextSize(2);
		matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
		matrix.setTextColor(adafruit::ledbackpack::LED_ON);
		for (int8_t x=0; x>=-64; x--) {
			matrix.clear();
			matrix.setCursor(x,0);
			matrix.print("Hello");
			matrix.writeDisplay();
			nanosleep(&sleep100, nullptr);
		}

		matrix.setTextSize(1);
		matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
		matrix.setTextColor(adafruit::ledbackpack::LED_ON);
		matrix.setRotation(1);
		for (int8_t x=7; x>=-36; x--) {
			matrix.clear();
			matrix.setCursor(x,0);
			matrix.print("World");
			matrix.writeDisplay();
			nanosleep(&sleep100, nullptr);
		}
		matrix.setRotation(0);
    }

    return 0;
}