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
    std::vector<Update> updates = m_api->getUpdates();
    if (!updates.empty()) {
        m_offset = updates.at(0).update_id;
    }
    m_update = [](const Telegram::Bot::Types::API &, const Update &) {};
}

void Telegram::Bot::Connector::callback() {
    m_offset = 0;
    std::thread threadupdate;
    threadupdate = std::thread(&Telegram::Bot::Connector::update, this);
    threadupdate.detach();
    while (1) {
        m_block.lock();
        auto size = m_values.size();
        m_block.unlock();
        if (size > 0) {
            Update update;
            m_block.lock();
            update = std::move(m_values.front());
            m_values.pop();
            m_block.unlock();
            m_update(*m_api, update);
        }
    }
}

void Telegram::Bot::Connector::update() {
    while (1) {
        std::vector<Update> updates = m_api->getUpdates("", 0, 0, m_offset + 1);
        if (!updates.empty()) {
            m_offset = updates.at(0).update_id;
            m_block.lock();
            m_values.push(std::move(updates.at(0)));
            m_block.unlock();
        }
    }
}

void Telegram::Bot::Connector::onUpdate(std::function<void(const Telegram::Bot::Types::API &, const Update &)> func) {
    m_update = func;
}

Telegram::Bot::Connector::~Connector() = default;