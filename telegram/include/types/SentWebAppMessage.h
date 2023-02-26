#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Describes an inline message sent by a <a href="/bots/webapps">Web App</a> on behalf of a user.
struct SentWebAppMessage{
	std::string inline_message_id;
};

