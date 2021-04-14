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
		inline void callback(std::function<void(TelegramTypes::API&, TelegramTypes::MessageReceive&)> func);
		inline void LOGA();
		~TelegramAPI();
	private:
		std::queue<Json::Value> values;
		std::string tokl;
		long long int offset;
		std::mutex block;
		TelegramTypes::API api = TelegramTypes::API("");
		inline void update();
		inline std::string buildString();
	};

}

inline size_t WriteaCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
TelegramBot::TelegramAPI::TelegramAPI(std::string token)
{
	JSONCPP_STRING err;
	Json::Value parsed;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	std::string update;
	tokl = token;
	std::cout << "The bot has started successfully!" << std::endl;
	api = TelegramTypes::API(buildString());
	update = buildString() + "/getUpdates";
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, update.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteaCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	Json::CharReaderBuilder builder;
	const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
	if (parsed["ok"].asString() == "true" && parsed["result"][0]["update_id"].asString() != "") {
		offset = parsed["result"][0]["update_id"].asInt64();
	}
}
inline void TelegramBot::TelegramAPI::callback(std::function<void(TelegramTypes::API&, TelegramTypes::MessageReceive&)> func)
{
	offset = 0;
	std::thread threadupdate;
	threadupdate = std::thread(&TelegramBot::TelegramAPI::update, this);
	threadupdate.detach();
	while (1) {
		block.lock();
		int size;
		size = 0;
		size = values.size();
		block.unlock();
		if (size>0) {
			Json::Value values2;
			block.lock();
			values2 = values.back()["result"][0];
			values.pop();
			block.unlock();
			if (values2["message"].isNull()) {
				values2 = values2["inline_query"];
			}
			else {
				values2 = values2["message"];
			}
			func(api, values2);
		}
	}
}

inline void TelegramBot::TelegramAPI::LOGA()
{
}
TelegramBot::TelegramAPI::~TelegramAPI()
{
}
inline void TelegramBot::TelegramAPI::update()
{
	while (1) {
		JSONCPP_STRING err;
		Json::Value parsed;
		CURL* curl;
		CURLcode res;
		std::string readBuffer;
		std::string aghl;
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
		reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
		if (parsed["ok"].asString() == "true" && parsed["result"][0]["update_id"].asString() != "") {
			offset = parsed["result"][0]["update_id"].asInt64();
			block.lock();
			values.push(parsed);
			block.unlock();
		}
	}
}
inline std::string TelegramBot::TelegramAPI::buildString()
{
	return "https://api.telegram.org/bot" + tokl;
}
