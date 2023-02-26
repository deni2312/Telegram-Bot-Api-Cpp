#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "MessageEntity.h"
//Represents the <a href="#inputmessagecontent">content</a> of a text message to be sent as the result of an inline query.
struct InputTextMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
};

