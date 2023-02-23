#pragma once

#include <sstream>

#include <array>

#include <fstream>

#include <vector>

#include <thread>

#include <queue>

#include "types.h"

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
			void update();
			std::shared_ptr<Types::Network> m_request;
		};
	}
}
