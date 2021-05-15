#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {

	try {
		Json::Value toSend;
		toSend[0]["type"] = "article";
		toSend[0]["id"] = "first";
		toSend[0]["title"] = "hey";
		toSend[0]["input_message_content"]["message_text"] = "hey";
		api.answerInlineQuery(toSend, message["id"].asString());
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