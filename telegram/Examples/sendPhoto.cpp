#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(TelegramTypes::API& api, TelegramTypes::MessageReceive& message) {
	try { //if the second peremeter is a void string it will send the link of the photo, otherwise it will takes as third peremeter the directory of the photo
		api.sendPhoto(message["chat"]["id"].asString(), "", "https://upload.wikimedia.org/wikipedia/commons/thumb/4/4e/Macaca_nigra_self-portrait_large.jpg/800px-Macaca_nigra_self-portrait_large.jpg");
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


