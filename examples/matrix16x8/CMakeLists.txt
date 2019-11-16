#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
PROJECT(Matrix16x8)

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

# Add MakeImage post-build command
INCLUDE("${AZURE_SPHERE_MAKE_IMAGE_FILE}")