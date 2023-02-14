#include <utility>

#include "../include/TelegramAPI.h"

inline size_t WriteaCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
Telegram::Bot::Connector::Connector(std::string token) : tokl{ std::move(token) }, request{ std::make_shared<Types::HTTPrequest>("https://api.telegram.org/bot" + tokl) },api{std::make_shared<Telegram::Bot::Types::API>("https://api.telegram.org/bot" + tokl,request)}
{
	JSONCPP_STRING err;
	Json::Value parsed;
	std::string readBuffer;
	std::string update;
	std::cout << "The bot has started successfully!" << std::endl;
	update = "/getUpdates";
    readBuffer = request->sendHttp(update).asString();
	Json::CharReaderBuilder builder;
	const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
	if (parsed["ok"].asString() == "true" && !parsed["result"][0]["update_id"].asString().empty()) {
		offset = parsed["result"][0]["update_id"].asInt64();
	}
}
void Telegram::Bot::Connector::callback(const std::function<void(const Telegram::Bot::Types::API&, const Telegram::Bot::Types::MessageReceive&)>& func)
{
	offset = 0;
	std::thread threadupdate;
	threadupdate = std::thread(&Telegram::Bot::Connector::update, this);
	threadupdate.detach();
	while (1) {
		block.lock();
		auto size = values.size();
		block.unlock();
		if (size > 0) {
			Json::Value values2;
			block.lock();
			values2 = std::move(values.front()["result"][0]);
			values.pop();
			block.unlock();
			if (values2["message"].isNull()) {
				values2 = std::move(values2["inline_query"]);
			}
			else {
				values2 = std::move(values2["message"]);
			}
			func(*api, values2);
		}
	}
}

Telegram::Bot::Connector::~Connector() = default;
void Telegram::Bot::Connector::update()
{
	while (1) {
		JSONCPP_STRING err;
		Json::Value parsed;
		std::string readBuffer;
		std::string aghl;
		aghl = "/getUpdates?offset=" + std::to_string(offset + 1);
        readBuffer = request->sendHttp(aghl).asString();
		Json::CharReaderBuilder builder;
		const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
		reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
		if (parsed["ok"].asString() == "true" && !parsed["result"][0]["update_id"].asString().empty()) {
			offset = parsed["result"][0]["update_id"].asInt64();
			block.lock();
			values.push(std::move(parsed));
			block.unlock();
		}
	}
}