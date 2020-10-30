#  Copyright (c) Alan Ludwig. All rights reserved.
#  Licensed under the MIT License.

# Create executable
ADD_EXECUTABLE(
	seven_segment_blink  
	main.cpp
	../../Adafruit_LEDBackpack.cpp
	../../Adafruit_LEDBackpack.h
	../../Adafruit_GFX.cpp
	../../Adafruit_GFX.h
	../../Print.cpp
	../../Print.h
)

TARGET_LINK_LIBRARIES(seven_segment_blink  applibs pthread gcc_s c)

azsphere_target_add_image_package(seven_segment_blink)


