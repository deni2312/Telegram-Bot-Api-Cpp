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


namespace Telegram{
	namespace Bot {
		class Connector {
		public:
			Connector() = delete;
			Connector& operator=(const Connector& connector) = delete;
			explicit Connector(std::string token);
			void callback(const std::function<void(const Telegram::Bot::Types::API&, const Message&)>& func);
			~Connector();
		private:
			std::queue<Message> m_values;
			std::string m_token;
			long long int m_offset;
			std::mutex m_block;
			std::shared_ptr<Telegram::Bot::Types::API> m_api;
			inline void update(){
                while (1) {
                    nlohmann::json parsed;
                    std::string readBuffer;
                    std::string aghl;
                    aghl = "/getUpdates?offset=" + std::to_string(m_offset + 1);
                    readBuffer = m_request->sendHttp(aghl).asString();
                    parsed=nlohmann::json::object();
                    parsed=nlohmann::json::parse(readBuffer);
                    if (parsed["ok"] == true && !parsed["result"][0]["update_id"].empty()) {
                        m_offset = parsed["result"][0]["update_id"];
                        m_block.lock();
                        Message message;
                        from_json(parsed["result"][0]["message"],message);
                        m_values.push(std::move(message));
                        m_block.unlock();
                    }
                }
            }
			std::shared_ptr<Types::Network> m_request;
		};
	}
}
