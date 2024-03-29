#include <utility>

#include "../include/TelegramAPI.h"

Telegram::Bot::Connector::Connector(std::string token, std::string local) : m_token{
        std::move(token)}, m_request{
        std::make_shared<Types::HTTPrequest>(local + "/bot" + m_token)},
                                                                            m_api{std::make_shared<Telegram::Bot::Types::API>(
                                                                                    local + "/bot" +
                                                                                    m_token,
                                                                                    m_request)} {
    std::string readBuffer;
    std::string update;
    std::cout << "The bot has started successfully!" << std::endl;
    std::vector<Update> updates = m_api->getUpdates();
    if (!updates.empty()) {
        m_offset = updates.at(0).update_id;
    }
    m_update = [](const Telegram::Bot::Types::API &, const Update &) {};
}

void Telegram::Bot::Connector::callback(unsigned int timeout) {
    m_offset = 0;
    m_timeout = timeout;
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
        std::vector<Update> updates = m_api->getUpdates("", m_timeout, 0, m_offset + 1);
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
