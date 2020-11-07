#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(TelegramTypes::API& api, TelegramTypes::MessageReceive& message) {
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

	TelegramBot::TelegramAPI handler("your-token");
	handler.callback(sendSomething);
}


