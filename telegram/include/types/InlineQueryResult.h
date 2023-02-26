#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InputMessageContent.h"
#include "InlineKeyboardMarkup.h"
//This object represents one result of an inline query. Telegram clients currently support results of the following 20 types:
struct InlineQueryResult{
	std::string type;
	std::string id;
	std::string title;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::string url;
	bool hide_url;
	std::string description;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

