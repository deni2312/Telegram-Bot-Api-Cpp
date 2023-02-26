#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Describes that no specific value for the menu button was set.
struct MenuButtonDefault{
	std::string type;
};

