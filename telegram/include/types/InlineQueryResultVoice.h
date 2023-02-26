#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "MessageEntity.h"
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
//Represents a link to a voice recording in an .OGG container encoded with OPUS. By default, this voice recording will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the the voice message.
struct InlineQueryResultVoice{
	std::string type;
	std::string id;
	std::string voice_url;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	int voice_duration;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

