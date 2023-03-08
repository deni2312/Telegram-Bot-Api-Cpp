mkdir build
cmake -B build/ -S . -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build/
./build/TelegramBotApiCpp
