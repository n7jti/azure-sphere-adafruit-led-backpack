#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
PROJECT(7_Segment_Blink)

# Create executable
ADD_EXECUTABLE(
	${PROJECT_NAME} 
	main.cpp
	../../Adafruit_LEDBackpack.cpp
	../../Adafruit_LEDBackpack.h
)

#set_target_properties(7_Segment_Blink PROPERTIES CXX_STANDARD 17)
set_target_properties(7_Segment_Blink PROPERTIES LINKER_LANGUAGE C)


TARGET_LINK_LIBRARIES(${PROJECT_NAME} applibs pthread gcc_s c)

# Add MakeImage post-build command
INCLUDE("${AZURE_SPHERE_MAKE_IMAGE_FILE}")