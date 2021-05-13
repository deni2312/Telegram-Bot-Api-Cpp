#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(TelegramTypes::API& api, TelegramTypes::MessageReceive& message) {
	try {//if the second peremeter is a void string it will send the link of the photo, otherwise it will takes as third peremeter the directory of the photo
		Json::Value file;
		file = api.getFile("your-file-id");
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


