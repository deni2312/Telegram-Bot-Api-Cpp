#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(const TelegramTypes::API& api, const TelegramTypes::MessageReceive& message) {
}

int main()
{
	TelegramBot::TelegramAPI handler("your-token");
	handler.callback(sendSomething);
}