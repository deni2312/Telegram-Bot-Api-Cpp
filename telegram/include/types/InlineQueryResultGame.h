#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InlineKeyboardMarkup.h"
//Represents a <a href="#games">Game</a>.
struct InlineQueryResultGame{
	std::string type;
	std::string id;
	std::string game_short_name;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
};

