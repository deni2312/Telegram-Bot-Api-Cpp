#include <iostream>

#include "telegram/include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API &api, const Update &update) {
    try {
        Chat chat = api.getChat(update.message->chat->id);
        std::cout << "Your chat first name is: " + chat.first_name << std::endl;
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
