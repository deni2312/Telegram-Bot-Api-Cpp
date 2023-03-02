#include <iostream>

#include "telegram/include/TelegramAPI.h"

void sendSomething(const Telegram::Bot::Types::API &api, const Update &update) {
    try {
        std::vector<std::shared_ptr<InlineQueryResult>> results;
        std::shared_ptr<InlineQueryResult> result = std::make_shared<InlineQueryResult>();
        result->type = "article";
        result->id = "first";
        result->title = "hey";
        result->input_message_content = std::make_shared<InputMessageContent>();
        result->input_message_content->message_text = "Hey";
        results.push_back(result);
        api.answerInlineQuery(update.inline_query->id, results);
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
