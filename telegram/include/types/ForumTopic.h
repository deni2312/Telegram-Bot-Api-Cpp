#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a forum topic.
struct ForumTopic{
	int message_thread_id;
	std::string name;
	int icon_color;
	std::string icon_custom_emoji_id;
};

