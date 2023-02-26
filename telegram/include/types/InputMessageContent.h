#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "MessageEntity.h"
//This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 5 types:
struct InputMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
};

