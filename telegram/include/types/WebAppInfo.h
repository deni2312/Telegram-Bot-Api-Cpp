#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Describes a <a href="/bots/webapps">Web App</a>.
struct WebAppInfo{
	std::string url;
};

