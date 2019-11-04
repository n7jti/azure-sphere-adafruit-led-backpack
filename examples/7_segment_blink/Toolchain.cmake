SET(CMAKE_SYSTEM_NAME Generic)
SET(AZURE_SPHERE_SDK_PATH "C:/Program Files (x86)/Microsoft Azure Sphere SDK" CACHE INTERNAL "Path to the Azure Sphere SDK")
SET(AZURE_SPHERE_API_SET "3")
SET(AZURE_SPHERE_CMAKE_PATH "${AZURE_SPHERE_SDK_PATH}/CMakeFiles")

SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

SET(AZURE_SPHERE_MAKE_IMAGE_FILE "${AZURE_SPHERE_CMAKE_PATH}/AzureSphereMakeImage.cmake" CACHE INTERNAL "Path to the MakeImage CMake target")

# Disable linking during try_compile since our link options cause the generation to fail
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY CACHE INTERNAL "Disable linking for try_compile")

SET(AZURE_SPHERE_API_SET_DIR "${AZURE_SPHERE_SDK_PATH}/Sysroots/${AZURE_SPHERE_TARGET_API_SET}" CACHE INTERNAL "Path to the selected API set in the Azure Sphere SDK")
SET(ENV{PATH} "${AZURE_SPHERE_SDK_PATH}/Tools;${AZURE_SPHERE_API_SET_DIR}/tools/gcc;$ENV{PATH}")
SET(CMAKE_FIND_ROOT_PATH "${AZURE_SPHERE_API_SET_DIR}")

SET(CMAKE_C_COMPILER "${AZURE_SPHERE_API_SET_DIR}/tools/gcc/arm-poky-linux-musleabi-gcc.exe" CACHE INTERNAL "Path to the C compiler in the selected API set targeting High-Level core")
SET(CMAKE_CXX_COMPILER "${AZURE_SPHERE_API_SET_DIR}/tools/gcc/arm-poky-linux-musleabi-gcc.exe" CACHE INTERNAL "Path to the C compiler in the selected API set targeting High-Level core")

SET(CMAKE_C_FLAGS_INIT "-B \"${AZURE_SPHERE_API_SET_DIR}/tools/gcc\" -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard \
-mcpu=cortex-a7 --sysroot=\"${AZURE_SPHERE_API_SET_DIR}\"")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "-nodefaultlibs -pie -Wl,--no-undefined -Wl,--gc-sections")

SET(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES "${AZURE_SPHERE_API_SET_DIR}/usr/include")

ADD_DEFINITIONS(-D_POSIX_C_SOURCE)
SET(COMPILE_DEBUG_FLAGS $<$<CONFIG:Debug>:-ggdb> $<$<CONFIG:Debug>:-O0>)
SET(COMPILE_RELEASE_FLAGS $<$<CONFIG:Release>:-g1> $<$<CONFIG:Release>:-Os>)
ADD_COMPILE_OPTIONS(-std=c11 ${COMPILE_DEBUG_FLAGS} ${COMPILE_RELEASE_FLAGS} -fPIC
                    -ffunction-sections -fdata-sections -fno-strict-aliasing
                    -fno-omit-frame-pointer -fno-exceptions -Wall -Wstrict-prototypes
                    -Wswitch -Wempty-body -Wconversion -Wreturn-type -Wparentheses
                    -Wno-pointer-sign -Wno-format -Wuninitialized -Wunreachable-code
                    -Wunused-function -Wunused-value -Wunused-variable
                    -Werror=implicit-function-declaration -fstack-protector-strong)

