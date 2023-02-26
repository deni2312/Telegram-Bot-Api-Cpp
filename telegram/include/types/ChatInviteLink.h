#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//Represents an invite link for a chat.
struct ChatInviteLink{
	std::string invite_link;
	std::shared_ptr<User> creator;
	bool creates_join_request;
	bool is_primary;
	bool is_revoked;
	std::string name;
	int expire_date;
	int member_limit;
	int pending_join_request_count;
};

