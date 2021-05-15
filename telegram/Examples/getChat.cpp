#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {
	try {
		Json::Value file;
		file = api.getChat(message["chat"]["id"].asString());
		std::cout << file;
	}
	catch (std::string& error) {
		std::cerr << error;
	}
}

int main()
{

	Telegram::Bot::Connector handler("your-token");
	handler.callback(sendSomething);
}


