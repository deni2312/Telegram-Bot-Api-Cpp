
#include <iostream>

#include "include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API& api, const Telegram::Bot::Types::MessageReceive& message) {
}

int main()
{
	Telegram::Bot::Connector handler("your-token");
	handler.callback(sendSomething);
}
