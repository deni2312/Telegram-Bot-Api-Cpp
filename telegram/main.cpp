#include <iostream>

#include "include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {
	
	try {
		api.sendPhoto(message["chat"]["id"].asString(),"","https://www.donnamoderna.com/content/uploads/2020/07/Immagini-rilassanti-di-panorami-naturali-830x625.jpg");
	}
	catch (Telegram::Bot::Types::Error& error) {
		std::cerr << error.what();
	}
}

int main()
{
	std::unique_ptr<HTTPrequest> request;
	Telegram::Bot::Connector handler("555443656:AAEpy90Jb7cvUk1-HYyQtT20qJj5Hubrdww");
	handler.callback(sendSomething);
}
