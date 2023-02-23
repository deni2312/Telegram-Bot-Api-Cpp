#include <iostream>

#include "include/TelegramAPI.h"
inline void sendSomething(const Telegram::Bot::Types::API& api, const Message& message) {
	try {
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
