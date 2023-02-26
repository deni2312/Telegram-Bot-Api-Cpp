#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "MessageEntity.h"
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
//Represents a link to a photo. By default, this photo will be sent by the user with optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the photo.
struct InlineQueryResultPhoto{
	std::string type;
	std::string id;
	std::string photo_url;
	std::string thumb_url;
	int photo_width;
	int photo_height;
	std::string title;
	std::string description;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

