#  Copyright (c) Alan Ludwig. All rights reserved.
#  Licensed under the MIT License.



cmake_minimum_required(VERSION 3.11)
project (7_segment_Blink CXX)

azsphere_configure_tools(TOOLS_REVISION "20.07")
azsphere_configure_api(TARGET_API_SET "6")

# Create executable
ADD_EXECUTABLE(
	${PROJECT_NAME}  
	main.cpp
	../../Adafruit_LEDBackpack.cpp
	../../Adafruit_LEDBackpack.h
	../../Adafruit_GFX.cpp
	../../Adafruit_GFX.h
	../../Print.cpp
	../../Print.h
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}  applibs pthread gcc_s c)

azsphere_target_add_image_package(${PROJECT_NAME})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

