#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Describes data sent from a <a href="/bots/webapps">Web App</a> to the bot.
struct WebAppData{
	std::string data;
	std::string button_text;
};

