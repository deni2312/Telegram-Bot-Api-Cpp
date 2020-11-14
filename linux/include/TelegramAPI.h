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
		inline void callback(std::function<void(TelegramTypes::API&, TelegramTypes::MessageReceive&)> func);
		
		inline void LOGA();
		~TelegramAPI();
	private: 
		Json::Value values;
		bool firstCall;
		int onUpdate;
		std::string tokl;
		long long int offset;
		std::mutex nmop;
		TelegramTypes::API api=TelegramTypes::API("");
		inline void update();
		inline std::string buildString();
	};
	
}


TelegramBot::TelegramAPI::TelegramAPI(std::string token)
{
	std::cout << "The bot has started successfully!" << std::endl;
	tokl = token;
	api = TelegramTypes::API(buildString());
}
inline void TelegramBot::TelegramAPI::callback(std::function<void(TelegramTypes::API&, TelegramTypes::MessageReceive&)> func)
{
	offset = 0;
	firstCall = true;
	while (1) {
		update();
		if (onUpdate == 1) {
			std::thread([&]() {
				std::lock_guard<std::mutex> gi(nmop);
				Json::Value values2;
				values2 = Json::Value(values["result"][0]);
				if (values2["message"].isNull()) {
					values2 = values2["inline_query"];
				}
				else {
					values2 = values2["message"];
				}
				func(api, values2);
			}).detach();
		}
	}
}

inline void TelegramBot::TelegramAPI::LOGA()
{
}
TelegramBot::TelegramAPI::~TelegramAPI()
{
}
inline size_t WriteaCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
inline void TelegramBot::TelegramAPI::update()
{
	onUpdate = 0;
	JSONCPP_STRING err;
	Json::Value vnkl;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	std::string aghl;
	if (firstCall) {
		aghl = buildString() + "/getUpdates";
		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, aghl.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteaCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
		Json::CharReaderBuilder builder;
		const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
		reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &vnkl, &err);
		if (vnkl["ok"].asString() == "true" && vnkl["result"][0]["update_id"].asString() != "") {
			firstCall = false;
			onUpdate = true;
		}
	}
	else {
		aghl = buildString() + "/getUpdates?offset=" + std::to_string(offset + 1);
		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, aghl.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteaCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
		Json::CharReaderBuilder builder;
		const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
		reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &vnkl, &err);
		if (vnkl["ok"].asString() == "true" && vnkl["result"][0]["update_id"].asString() != "") {
			onUpdate = true;
		}
		else {
			onUpdate = false;
		}
	}
	if (onUpdate) {
		offset = vnkl["result"][0]["update_id"].asInt64();
		values = vnkl;
	}
}
inline std::string TelegramBot::TelegramAPI::buildString()
{
	return "https://api.telegram.org/bot" + tokl;
}
