#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//This object represents a service message about new members invited to a video chat.
struct VideoChatParticipantsInvited{
	std::vector<std::shared_ptr<User>> users;
};

