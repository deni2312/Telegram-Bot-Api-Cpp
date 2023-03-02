#include <iostream>

#include "telegram/include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API &api, const Update &update) {
    try {
        api.sendMessage(update.message->chat->id, "Hello world!");
    }
    catch (Telegram::Bot::Types::Error &error) {
        std::cerr << error.what();
    }
}

int main(int argc, char **argv) {

    try {
        Telegram::Bot::Connector handler(argv[1]);//Insert here your token
        handler.onUpdate(sendSomething);
        handler.callback();
    }
    catch (Telegram::Bot::Types::Error &error) {
        std::cerr << error.what();
    }
}
