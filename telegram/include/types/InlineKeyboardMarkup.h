#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InlineKeyboardButton.h"
//This object represents an <a href="/bots/features#inline-keyboards">inline keyboard</a> that appears right next to the message it belongs to.
struct InlineKeyboardMarkup{
	std::vector<std::shared_ptr<InlineKeyboardButton>> inline_keyboard;
};

