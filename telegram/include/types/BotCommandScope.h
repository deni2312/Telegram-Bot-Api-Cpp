#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents the scope to which bot commands are applied. Currently, the following 7 scopes are supported:
struct BotCommandScope{
	std::string type;
};

