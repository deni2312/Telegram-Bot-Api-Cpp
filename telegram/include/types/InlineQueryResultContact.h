#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
//Represents a contact with a phone number. By default, this contact will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the contact.
struct InlineQueryResultContact{
	std::string type;
	std::string id;
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	std::string vcard;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

