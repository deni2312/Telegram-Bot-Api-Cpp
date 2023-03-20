
#  C++ Telegram Bot API



<p align="left">This is a C++ library for interacting with the Telegram Bot API. It provides a simple and convenient way to send and receive messages, manage chats and users, and perform other bot-related tasks using the C++ programming language.  It's updated to <b>latest Telegram API version</b>.
    
  
  * [Features](#features)
  * [Getting started.](#getting-started)
  * [Writing your first bot](#writing-your-first-bot)
  * [General API Documentation](#general-api-documentation)
    * [Usage](#usage)
    * [Error Handling](#error-handling)
  * [Contacts](#contacts)
  
  
  ## Features

- Easy-to-use interface for sending and receiving messages, photos, videos, and other types of media
- Simple and intuitive methods for managing chats and users, including sending messages to groups
- Comprehensive support for all Telegram Bot API methods, including message editing, inline queries, and more
- Built-in support for long polling
- Lightweight and efficient, with minimal dependencies
  

## Getting started.

This API uses C++ 17, it supports Linux (g++) and Windows (Visual Studio 2019/2022).
 
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

#### Windows x64
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
    
You can install it through our **install.sh**(remember to give it right permissions) script or manually:
```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install nlohmann-json
./vcpkg install cpr
./vcpkg integrate install
```  
And you can run it with our **run.sh** or with CMake:  
```bash
cd Telegram-Bot-Api-Cpp
mkdir build
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

The **api** paramater contains all methods of Telegram APIs.  
The **update** paramater is the JSON rappresentation of the update sent by the user.  
Here's an example where we access to the chat-id paramater taken by Telegram APIs documentation: 
```c++
update.message->chat->id
 ```

You can check the examples folder for further information.

### Error Handling

To handle errors catch `Telegram::Bot::Types::Error &e` and the output of `e.what()` will be the JSON error returned by Telegram.
