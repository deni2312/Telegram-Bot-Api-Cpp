#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object describes the bot&#39;s menu button in a private chat. It should be one of
struct MenuButton{
	std::string type;
};

