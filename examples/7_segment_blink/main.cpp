/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

// This minimal Azure Sphere app repeatedly toggles GPIO 8, which is the red channel of RGB
// LED 1 on the MT3620 RDB. Use this app to test that device and SDK installation succeeded
// that you can build, deploy, and debug a CMake app with Visual Studio.
//
// It uses the API for the following Azure Sphere application libraries:
// - log (messages shown in Visual Studio's Device Output window during debugging)

#include <errno.h>
#include <string.h>
#include <time.h>
#include <applibs/log.h>

#include "../../Adafruit_LEDBackpack.h"

int main(void)
{
    Log_Debug("Starting 7-Segment Blink application...\n");
	
    Adafruit_7segment sevseg; 

    const struct timespec sleepTime = {1, 0};
	init_Adafruit_7segment(&sevseg, 0, 0x70);
	open_Adafruit_7segment(&sevseg); 

    while (true) {
		//print_long_Adafruit_7segment(&sevseg, 8888, 10);
		writeDigitNum_Adafruit_7segment(&sevseg, 0, 8, true);
		writeDigitNum_Adafruit_7segment(&sevseg, 1, 8, true);
		drawColon_Adafruit_7segment(&sevseg, true);
		writeDigitNum_Adafruit_7segment(&sevseg, 3, 8, true);
		writeDigitNum_Adafruit_7segment(&sevseg, 4, 8, true);
		
		writeDisplay_Adafruit_LEDBackpack(&sevseg.backpack);
		nanosleep(&sleepTime, NULL);

		clear_Adafruit_LEDBackpack(&sevseg.backpack);
		writeDisplay_Adafruit_LEDBackpack(&sevseg.backpack);
		nanosleep(&sleepTime, NULL);
    }

    return 0;
}