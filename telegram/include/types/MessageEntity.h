#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//This object represents one special entity in a text message. For example, hashtags, usernames, URLs, etc.
struct MessageEntity{
	std::string type;
	int offset;
	int length;
	std::string url;
	std::shared_ptr<User> user;
	std::string language;
	std::string custom_emoji_id;
};

