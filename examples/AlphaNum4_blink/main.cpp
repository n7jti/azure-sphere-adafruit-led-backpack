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

extern "C" void __cxa_pure_virtual() { while (1); }

using adafruit::ledbackpack::Adafruit_AlphaNum4;

int main(void)
{
    Log_Debug("Starting AlphaNum4_blink Blink application...\n");
	
	Adafruit_AlphaNum4 alpha(0);

    const struct timespec sleepTime = {1, 0};
	alpha.begin(0x70);

    while (true) {
		//print_long_Adafruit_7segment(&sevseg, 8888, 10);
		alpha.writeDigitAscii(0, 'A');
		alpha.writeDigitAscii(1, 'L');
		alpha.writeDigitAscii(2, 'A');
		alpha.writeDigitAscii(3, 'N');
		alpha.writeDisplay();

		
		nanosleep(&sleepTime, nullptr);

		alpha.clear();
		alpha.writeDisplay();

		nanosleep(&sleepTime, nullptr);
    }

    return 0;
}