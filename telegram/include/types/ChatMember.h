#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//This object contains information about one member of a chat. Currently, the following 6 types of chat members are supported:
struct ChatMember{
	std::string status;
	std::shared_ptr<User> user;
	bool is_anonymous;
	std::string custom_title;
};

