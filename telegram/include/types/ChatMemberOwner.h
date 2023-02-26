#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//Represents a <a href="#chatmember">chat member</a> that owns the chat and has all administrator privileges.
struct ChatMemberOwner{
	std::string status;
	std::shared_ptr<User> user;
	bool is_anonymous;
	std::string custom_title;
};

