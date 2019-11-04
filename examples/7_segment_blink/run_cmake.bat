@echo on
mkdir build
cd build

cmake.exe -G "Ninja" ^
-DCMAKE_INSTALL_PREFIX:PATH="." ^
-DCMAKE_TOOLCHAIN_FILE="Toolchain.cmake" ^
-DAZURE_SPHERE_TARGET_API_SET="3" ^
--no-warn-unused-cli ^
-DCMAKE_BUILD_TYPE="Debug" ^
-DCMAKE_MAKE_PROGRAM="ninja.exe" ^
..