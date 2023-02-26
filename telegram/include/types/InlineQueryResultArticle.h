#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InputMessageContent.h"
#include "InlineKeyboardMarkup.h"
//Represents a link to an article or web page.
struct InlineQueryResultArticle{
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

