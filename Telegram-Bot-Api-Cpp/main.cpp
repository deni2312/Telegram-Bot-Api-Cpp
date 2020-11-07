#include "include/TelegramAPI.h"
#include <iostream>

void sendSomething(TelegramTypes::API& api, TelegramTypes::MessageReceive& message) {
}

int main()
{
	TelegramBot::TelegramAPI handler("your-token");
	handler.callback(sendSomething);
}
