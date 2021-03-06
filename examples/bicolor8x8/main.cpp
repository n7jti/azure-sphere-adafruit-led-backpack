/*************************************************** 
  This is a library for our I2C LED Backpacks
  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870
  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

  Ported to the Azure Sphere by Alan Ludwig (N7JTI)
 ****************************************************/

#include <errno.h>
#include <string.h>
#include <time.h>
#include <applibs/log.h>

#include "../../Adafruit_LEDBackpack.h"

extern "C" void __cxa_pure_virtual() { while (1); }

using adafruit::ledbackpack::Adafruit_BicolorMatrix;

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
    Log_Debug("Starting 8x8 LED Matrix Test...\n");
    
    Adafruit_BicolorMatrix matrix(0);

    const struct timespec sleep500 = {0, 500000000};
    const struct timespec sleep100 = {0, 100000000};
    matrix.begin(0x70);

    while (true) {
      matrix.clear();
    matrix.drawBitmap(0, 0, smile_bmp, 8, 8, adafruit::ledbackpack::LED_GREEN);
    matrix.writeDisplay();
    nanosleep(&sleep500, nullptr);

    matrix.clear();
    matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, adafruit::ledbackpack::LED_YELLOW);
    matrix.writeDisplay();
    nanosleep(&sleep500, nullptr);;

    matrix.clear();
    matrix.drawBitmap(0, 0, frown_bmp, 8, 8, adafruit::ledbackpack::LED_RED);
    matrix.writeDisplay();
    nanosleep(&sleep500, nullptr);;

    matrix.clear();      // clear display
    matrix.drawPixel(0, 0, adafruit::ledbackpack::LED_GREEN);
    matrix.writeDisplay();  // write the changes we just made to the display
    nanosleep(&sleep500, nullptr);;

    matrix.clear();
    matrix.drawLine(0,0, 7,7, adafruit::ledbackpack::LED_YELLOW);
    matrix.writeDisplay();  // write the changes we just made to the display
    nanosleep(&sleep500, nullptr);;

    matrix.clear();
    matrix.drawRect(0,0, 8,8, adafruit::ledbackpack::LED_RED);
    matrix.fillRect(2,2, 4,4, adafruit::ledbackpack::LED_GREEN);
    matrix.writeDisplay();  // write the changes we just made to the display
    nanosleep(&sleep500, nullptr);;

    matrix.clear();
    matrix.drawCircle(3,3, 3, adafruit::ledbackpack::LED_YELLOW);
    matrix.writeDisplay();  // write the changes we just made to the display
    nanosleep(&sleep500, nullptr);;

    matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
    matrix.setTextSize(1);
    matrix.setTextColor(adafruit::ledbackpack::LED_GREEN);
    for (int8_t x=7; x>=-36; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("Hello");
      matrix.writeDisplay();
      nanosleep(&sleep100, nullptr);;
    }
    matrix.setRotation(3);
    matrix.setTextColor(adafruit::ledbackpack::LED_RED);
    for (int8_t x=7; x>=-36; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("World");
      matrix.writeDisplay();
      nanosleep(&sleep100, nullptr);;
    }
    matrix.setRotation(0);
  }
    return 0;
}