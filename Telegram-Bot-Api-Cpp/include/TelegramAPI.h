#pragma once

#include <sstream>
#include <array>
#include <fstream>
#include <vector>
#include "types.h"

namespace TelegramBot {


	class TelegramAPI {
	public:
		TelegramAPI(std::string token);
		void callback(std::function<void(TelegramTypes::API&, TelegramTypes::MessageReceive&)> func);
		
		void LOGA();
		~TelegramAPI();
	private: 
		Json::Value values;
		bool firstCall;
		int onUpdate;
		std::string tokl;
		long long int offset;
		
		TelegramTypes::API api=TelegramTypes::API("");
		void update();
		std::string buildString();
	};
	
}