#include <utility>

#include "../include/TelegramAPI.h"

inline size_t WriteaCallback(char *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

Telegram::Bot::Connector::Connector(std::string token) : m_token{std::move(token)}, m_request{
        std::make_shared<Types::HTTPrequest>("https://api.telegram.org/bot" + m_token)},
                                                         m_api{std::make_shared<Telegram::Bot::Types::API>(
                                                                 "https://api.telegram.org/bot" + m_token, m_request)} {
    std::string readBuffer;
    std::string update;
    std::cout << "The bot has started successfully!" << std::endl;
    update = "/getUpdates";
    readBuffer = m_request->sendHttp(update, "", false);
    nlohmann::json parsed;
    parsed = nlohmann::json::object();
    parsed = nlohmann::json::parse(readBuffer);
    if (parsed["ok"] == true && !parsed["result"][0]["update_id"].empty()) {
        m_offset = parsed["result"][0]["update_id"];
    }
}

void Telegram::Bot::Connector::callback(
        const std::function<void(const Telegram::Bot::Types::API &, const Message &)> &func) {
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
            values2 = std::move(m_values.front());
            m_values.pop();
            m_block.unlock();
            func(*m_api, values2);
        }
    }
}

void Telegram::Bot::Connector::update() {
    while (1) {
        nlohmann::json parsed;
        std::string readBuffer;
        std::string aghl;
        aghl = "/getUpdates?offset=" + std::to_string(m_offset + 1);
        readBuffer = m_request->sendHttp(aghl, "", false);
        parsed = nlohmann::json::object();
        parsed = nlohmann::json::parse(readBuffer);
        if (parsed["ok"] == true && !parsed["result"][0]["update_id"].empty()) {
            m_offset = parsed["result"][0]["update_id"];
            m_block.lock();
            Message message;
            from_json(parsed["result"][0]["message"], message);
            m_values.push(std::move(message));
            m_block.unlock();
        }
    }
}

Telegram::Bot::Connector::~Connector() = default;