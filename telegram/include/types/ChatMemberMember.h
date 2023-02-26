#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//Represents a <a href="#chatmember">chat member</a> that has no additional privileges or restrictions.
struct ChatMemberMember{
	std::string status;
	std::shared_ptr<User> user;
};

