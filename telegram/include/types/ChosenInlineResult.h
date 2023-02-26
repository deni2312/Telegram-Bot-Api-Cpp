#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
#include "Location.h"
//Represents a <a href="#inlinequeryresult">result</a> of an inline query that was chosen by the user and sent to their chat partner.
struct ChosenInlineResult{
	std::string result_id;
	std::shared_ptr<User> from;
	std::shared_ptr<Location> location;
	std::string inline_message_id;
	std::string query;
};

