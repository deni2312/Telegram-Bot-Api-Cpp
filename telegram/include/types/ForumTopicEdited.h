#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a service message about an edited forum topic.
struct ForumTopicEdited{
	std::string name;
	std::string icon_custom_emoji_id;
};

