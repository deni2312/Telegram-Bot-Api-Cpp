#include "../include/TelegramAPI.h"

inline size_t WriteaCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
Telegram::Bot::Connector::Connector(std::string token) : tokl{ token }, request{ std::make_shared<Types::HTTPrequest>("https://api.telegram.org/bot" + tokl) },api{std::make_shared<Telegram::Bot::Types::API>("https://api.telegram.org/bot" + tokl,request)}
{
	JSONCPP_STRING err;
	Json::Value parsed;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	std::string update;
	std::cout << "The bot has started successfully!" << std::endl;
	update = "/getUpdates";
	try {
		readBuffer = request->sendHttp(update).asString();
	}
	catch (Telegram::Bot::Types::Error& error) {
		std::cerr << error.what();
	}
	Json::CharReaderBuilder builder;
	const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
	if (parsed["ok"].asString() == "true" && parsed["result"][0]["update_id"].asString() != "") {
		offset = parsed["result"][0]["update_id"].asInt64();
		std::cout<<offset;
	}
}
void Telegram::Bot::Connector::callback(const std::function<void(const Telegram::Bot::Types::API&, const Telegram::Bot::Types::MessageReceive&)> func)
{
	offset = 0;
	std::thread threadupdate;
	threadupdate = std::thread(&Telegram::Bot::Connector::update, this);
	threadupdate.detach();
	while (1) {
		block.lock();
		int size;
		size = 0;
		size = values.size();
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

inline void Telegram::Bot::Connector::LOGA()
{
}
Telegram::Bot::Connector::~Connector()
{
}
void Telegram::Bot::Connector::update()
{
	while (1) {
		JSONCPP_STRING err;
		Json::Value parsed;
		CURL* curl;
		CURLcode res;
		std::string readBuffer;
		std::string aghl;
		aghl = "/getUpdates?offset=" + std::to_string(offset + 1);
		try {
			readBuffer = request.get()->sendHttp(aghl).asString();
		}
		catch (Telegram::Bot::Types::Error& error) {
			std::cerr << error.what();
		}
		Json::CharReaderBuilder builder;
		const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
		reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
		if (parsed["ok"].asString() == "true" && parsed["result"][0]["update_id"].asString() != "") {
			offset = parsed["result"][0]["update_id"].asInt64();
			block.lock();
			values.push(std::move(parsed));
			block.unlock();
		}
	}
}
inline std::string Telegram::Bot::Connector::buildString() const
{
	return "https://api.telegram.org/bot" + tokl;
}