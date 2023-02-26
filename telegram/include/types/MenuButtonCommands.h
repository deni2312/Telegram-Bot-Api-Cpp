#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents a menu button, which opens the bot&#39;s list of commands.
struct MenuButtonCommands{
	std::string type;
};

