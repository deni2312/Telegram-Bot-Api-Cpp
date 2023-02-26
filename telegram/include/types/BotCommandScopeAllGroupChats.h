#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chats.
struct BotCommandScopeAllGroupChats{
	std::string type;
};

