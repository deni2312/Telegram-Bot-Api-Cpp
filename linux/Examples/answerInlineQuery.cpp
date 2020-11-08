#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(TelegramTypes::API& api, TelegramTypes::MessageReceive& message) {

	try {
		Json::Value toSend;
		toSend["type"] = "article";
		toSend["id"] = "first";
		toSend["title"] = "hey";
		toSend["input_message_content"]["message_text"] = "hey";
		api.answerInlineQuery(toSend, message["id"].asString());
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