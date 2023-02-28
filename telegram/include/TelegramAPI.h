#pragma once

#include <sstream>

#include <array>

#include <fstream>

#include <vector>

#include <thread>

#include <queue>

#include "types.h"
#include "../include/network/HTTPrequest.h"

#include <iostream>


namespace Telegram {
    namespace Bot {
        class Connector {
        public:
            Connector() = delete;

            Connector &operator=(const Connector &connector) = delete;

            explicit Connector(std::string token);
            void onMessage(std::function<void(const Telegram::Bot::Types::API &, const Message &)> func);
            void onInline(std::function<void(const Telegram::Bot::Types::API &, const InlineQueryResult &)> func);
            void callback();

            ~Connector();

        private:
            std::queue<Message> m_values;
            std::string m_token;
            long long int m_offset;
            std::mutex m_block;
            std::shared_ptr<Telegram::Bot::Types::API> m_api;
            void update();
            std::shared_ptr<Types::Network> m_request;
            std::function<void(const Telegram::Bot::Types::API &, const Message &)> m_message;
            std::function<void(const Telegram::Bot::Types::API &, const InlineQueryResult &)> m_inline;
        };
    }
}
