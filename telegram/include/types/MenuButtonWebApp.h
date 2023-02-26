#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "WebAppInfo.h"
//Represents a menu button, which launches a <a href="/bots/webapps">Web App</a>.
struct MenuButtonWebApp{
	std::string type;
	std::string text;
	std::shared_ptr<WebAppInfo> web_app;
};

