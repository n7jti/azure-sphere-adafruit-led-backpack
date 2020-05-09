#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
PROJECT(Matrix8x8 CXX)

azsphere_configure_tools(TOOLS_REVISION "20.04")
azsphere_configure_api(TARGET_API_SET "5")

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

TARGET_LINK_LIBRARIES(${PROJECT_NAME} applibs pthread gcc_s c)

azsphere_target_add_image_package(${PROJECT_NAME})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")