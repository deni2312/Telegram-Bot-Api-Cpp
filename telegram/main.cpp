#include <iostream>

#include "include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {
	try {
		api.sendMessage(message["chat"]["id"].asString(), message["text"].asString());
	}
	catch (Telegram::Bot::Types::Error& error) {
		std::cerr << error.what();
	}
}

int main()
{
	Telegram::Bot::Connector handler("555443656:AAEpy90Jb7cvUk1-HYyQtT20qJj5Hubrdww");
	handler.callback(sendSomething);
}
