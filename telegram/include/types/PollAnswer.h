#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//This object represents an answer of a user in a non-anonymous poll.
struct PollAnswer{
	std::string poll_id;
	std::shared_ptr<User> user;
	int option_ids;
};

