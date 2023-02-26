#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "KeyboardButton.h"
//This object represents a <a href="/bots/features#keyboards">custom keyboard</a> with reply options (see <a href="/bots/features#keyboards">Introduction to bots</a> for details and examples).
struct ReplyKeyboardMarkup{
	std::vector<std::shared_ptr<KeyboardButton>> keyboard;
	bool is_persistent;
	bool resize_keyboard;
	bool one_time_keyboard;
	std::string input_field_placeholder;
	bool selective;
};

