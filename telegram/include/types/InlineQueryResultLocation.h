#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
//Represents a location on a map. By default, the location will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the location.
struct InlineQueryResultLocation{
	std::string type;
	std::string id;
	float latitude;
	float longitude;
	std::string title;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

