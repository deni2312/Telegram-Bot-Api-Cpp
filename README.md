
#  C++ Telegram Bot API



<p align="left">A header-only version of  <a href="https://core.telegram.org/bots/api">Telegram Bot API</a> in C++, updated to <b>latest version</b>
  
  * [Getting started.](#getting-started)
  * [Writing your first bot](#writing-your-first-bot)
  * [General API Documentation](#general-api-documentation)
    * [Usage](#usage)
    * [Error Handling](#error-handling)
  * [Contacts](#contacts)

## Getting started.

<h2> Steps </h2>

This API is tested with C++ 17, on linux g++ and on Visual Studio 2017/2019.
 
### Windows

* Install dependencies with VCPKG  
 ```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg install nlohmann-json
vcpkg install cpr
vcpkg integrate install
```  

####Windows x64
Most Windows machines are x64 now, but by default vcpkg uses x86 triplets (and installs x86 dependencies, if other is not set on your machine).
If you are not using Virtual Machine, then you need to make sure you have installed appropriate dependencies:
```bash
./vcpkg install nlohmann-json:x64-windows
./vcpkg install cpr:x64-windows
```  

* Clone the repository  
```bash
git clone https://github.com/deni2312/Telegram-Bot-Api-Cpp.git
```  

* Open CMakeFile on Visual Studio  
Files->Open->CMake->Telegram Directory


### Linux 
Install on linux with vcpkg:  
  * Dependencies
    * nlohmann-json
    * cpr  
```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install nlohmann-json
./vcpkg install cpr
./vcpkg integrate install
```  
With CMake:  
```bash
cd Telegram-Bot-Api-Cpp
mkdir build
cd build
cmake -B build/ -S . -DCMAKE_TOOLCHAIN_FILE=vcpkgdirectory/scripts/buildsystems/vcpkg.cmake
cd build
cmake --build .
./TelegramBotApiCpp
```  
Change vcpkgdirectory with the relative or absolute path of vcpkg  

## Writing your first bot

<h3>Hello World!</h3>

```c++
#include <iostream>

#include "telegram/include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API &api, const Update &update) {
    try {
        api.sendMessage(update.message->chat->id, "Hello world!");
    }
    catch (Telegram::Bot::Types::Error &error) {
        std::cerr << error.what();
    }
}

int main(int argc, char **argv) {

    try {
        Telegram::Bot::Connector handler(argv[1]);//Insert here your token
        handler.onUpdate(sendSomething);
        handler.callback();
    }
    catch (Telegram::Bot::Types::Error &error) {
        std::cerr << error.what();
    }
}


```


## General API Documentation

### Usage

The **api** paramater contains all methods of Telegram APIs, and **update** paramater contains the message sent by the user.  
The **update** paramater is the JSON rappresentation of the update sent by the user, and for example if you need to access the chat-id paramater you can simply type : 
```c++
update.message->chat->id
 ```

You can check the examples folder for further information.

### Error Handling

To handle errors catch `Telegram::Bot::Types::Error &e` and the output of `e.what()` will be the JSON error returned by Telegram.
