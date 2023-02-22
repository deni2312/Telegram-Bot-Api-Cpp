#include <utility>

#include "../include/TelegramAPI.h"

inline size_t WriteaCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
Telegram::Bot::Connector::Connector(std::string token) : m_token{ std::move(token) }, m_request{ std::make_shared<Types::HTTPrequest>("https://api.telegram.org/bot" + m_token) },m_api{std::make_shared<Telegram::Bot::Types::API>("https://api.telegram.org/bot" + m_token,m_request)}
{
    JSONCPP_STRING err;
    Json::Value parsed;
    std::string readBuffer;
    std::string update;
    std::cout << "The bot has started successfully!" << std::endl;
    update = "/getUpdates";
    readBuffer = m_request->sendHttp(update).asString();
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
    if (parsed["ok"].asString() == "true" && !parsed["result"][0]["update_id"].asString().empty()) {
        m_offset = parsed["result"][0]["update_id"].asInt64();
    }
}
void Telegram::Bot::Connector::callback(const std::function<void(const Telegram::Bot::Types::API&, const Message&)>& func)
{
    m_offset = 0;
    std::thread threadupdate;
    threadupdate = std::thread(&Telegram::Bot::Connector::update, this);
    threadupdate.detach();
    while (1) {
        m_block.lock();
        auto size = m_values.size();
        m_block.unlock();
        if (size > 0) {
            Message values2;
            m_block.lock();
            values2 = std::move(m_values.front()["result"][0]);
            m_values.pop();
            m_block.unlock();
            if (values2["message"].isNull()) {
                values2 = std::move(values2["inline_query"]);
            }
            else {
                values2 = std::move(values2["message"]);
            }
            func(*m_api, values2);
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
        aghl = "/getUpdates?offset=" + std::to_string(m_offset + 1);
        readBuffer = m_request->sendHttp(aghl).asString();
        Json::CharReaderBuilder builder;
        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
        reader->parse(readBuffer.c_str(), readBuffer.c_str() + readBuffer.length(), &parsed, &err);
        if (parsed["ok"].asString() == "true" && !parsed["result"][0]["update_id"].asString().empty()) {
            m_offset = parsed["result"][0]["update_id"].asInt64();
            m_block.lock();
            m_values.push(std::move(parsed));
            m_block.unlock();
        }
    }
}