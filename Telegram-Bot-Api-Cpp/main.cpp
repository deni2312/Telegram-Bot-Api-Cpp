#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(TelegramTypes::API &api, TelegramTypes::MessageReceive &message) {
	try {
		api.sendMessage(message["chat"]["id"].asString(),"Hello World!");
	}
	catch (std::string &error) {
		std::cerr << error;
	}
}

int main()
{
	TelegramBot::TelegramAPI handler("your-token");
	handler.callback(sendSomething);
}
