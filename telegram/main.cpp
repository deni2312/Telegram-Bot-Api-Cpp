#include <iostream>

#include "include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {
	
	try {
		api.sendMessage(message["chat"]["id"].asString(),"Hello world");
	}
	catch (Telegram::Bot::Types::Error& error) {
		std::cerr << error.what();
	}
}

int main()
{
	std::unique_ptr<HTTPrequest> request;
	Telegram::Bot::Connector handler("your-token");
	handler.callback(sendSomething);
}
