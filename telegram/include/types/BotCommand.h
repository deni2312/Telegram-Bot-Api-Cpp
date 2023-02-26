#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a bot command.
struct BotCommand{
	std::string command;
	std::string description;
};

