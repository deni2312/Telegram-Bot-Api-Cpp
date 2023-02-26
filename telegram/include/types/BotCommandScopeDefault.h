#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents the default <a href="#botcommandscope">scope</a> of bot commands. Default commands are used if no commands with a <a href="#determining-list-of-commands">narrower scope</a> are specified for the user.
struct BotCommandScopeDefault{
	std::string type;
};

