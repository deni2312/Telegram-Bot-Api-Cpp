
#  C++ Telegram Bot API



<p align="left">A header-only version of  <a href="https://core.telegram.org/bots/api">Telegram Bot API</a> in C++, updated to <b>5.0</b>
  
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
vcpkg install jsoncpp
vcpkg install cpr
vcpkg integrate install
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
    * Jsoncpp
    * cpr  
```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install jsoncpp
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
#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(Telegram::Bot::Types::API &api, Telegram::Bot::Types::MessageReceive &message) {
	try {
		api.sendMessage(message["chat"]["id"].asString(),"Hello World!");
	}
	catch (Telegram::Bot::Types::Error &error) {
		std::cerr << error.what();
	}
}

int main()
{
	Telegram::Bot::Connector handler("your-token");
	handler.callback(sendSomething);
}

```


## General API Documentation

### Usage

The **api** paramater contains all methods of Telegram APIs, and **message** paramater contains the message sent by the user.  
The **message** paramater is the JSON rappresentation of the message sent by the user, and for example if you need to access the chat-id paramater you can simply type : 
```c++
message["chat"]["id"]
 ```
By the <a href="https://core.telegram.org/bots/api">documentation</a>:  
sendMessage requires `chat_id`:

<p align="left">
  <img src="https://github.com/deni2312/Telegram-Bot-Api-Cpp/blob/master/bin/Image4.PNG" width="600" alt="accessibility text">
</p>

Then:

<p align="left">
  <img src="https://github.com/deni2312/Telegram-Bot-Api-Cpp/blob/master/bin/Image5.PNG" width="600" alt="accessibility text">
</p>

<p align="left">
  <img src="https://github.com/deni2312/Telegram-Bot-Api-Cpp/blob/master/bin/Image6.PNG" width="600" alt="accessibility text">
</p>
Or check the examples folder.

### Error Handling

To handle errors you only need to catch `Telegram::Bot::Types::Error &e` and the output of `e.what()` will be the JSON error returned by Telegram.

### Contacts

You can contact us on Telegram for any issue or doubt.  
<a href="https://t.me/deni2312"> @deni2312 </a><a href="https://t.me/jaguar114"> @jaguar114 </a> <a href="https://t.me/Ferro_nvm"> @Ferro_nvm </a>
