#include <iostream>

#include "include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API& api, const Message& message) {
	try {
        api.sendPhoto(message.chat->id,"C:/Users/denis.beqiraj/CLionProjects/Telegram-Bot-Api-Cpp/cmake-build-debug/b.jpg");
    }
	catch (Telegram::Bot::Types::Error& error) {
		std::cerr << error.what();
	}
}

int main(int argc, char** argv)
{

    try {
        Telegram::Bot::Connector handler(argv[1]);//Insert here your token
        handler.callback(sendSomething);
    }
    catch (Telegram::Bot::Types::Error& error) {
        std::cerr << error.what();
    }
}
