#include <iostream>

#include "include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {
	try {
		api.sendMessage(message["chat"]["id"].asString(), "Hello World!");
	}
	catch (Telegram::Bot::Types::Error& error) {
		std::cerr << error.what();
	}
}

int main()
{
	Telegram::Bot::Connector handler("your-token");
	handler.callback(sendSomething);
}
