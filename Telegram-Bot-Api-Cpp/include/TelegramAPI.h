#pragma once

#include <sstream>

#include <array>

#include <fstream>

#include <vector>

#include <thread>

#include <queue>

#include "types.h"

namespace TelegramBot {

	class TelegramAPI {
	public:
		TelegramAPI(std::string token);
		void callback(const std::function<void(const TelegramTypes::API&, const TelegramTypes::MessageReceive&)> func);
		inline void LOGA();
		~TelegramAPI();
	private:
		std::queue<Json::Value> values;
		std::string tokl;
		long long int offset;
		std::mutex block;
		TelegramTypes::API api;
		void update();
		inline std::string buildString() const;
	};

}
