#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a service message about a new forum topic created in the chat.
struct ForumTopicCreated{
	std::string name;
	int icon_color;
	std::string icon_custom_emoji_id;
};

