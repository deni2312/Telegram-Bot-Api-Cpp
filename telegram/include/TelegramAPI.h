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
			Connector(std::string token);
			void callback(const std::function<void(const Telegram::Bot::Types::API&, const Telegram::Bot::Types::MessageReceive&)> func);
			inline void LOGA();
			~Connector();
		private:
			std::queue<Json::Value> values;
			std::string tokl;
			long long int offset;
			std::mutex block;
			Telegram::Bot::Types::API api;
			void update();
			inline std::string buildString() const;
		};
	}
}
