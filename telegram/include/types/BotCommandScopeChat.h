#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific chat.
struct BotCommandScopeChat{
	std::string type;
	int chat_id;
};

