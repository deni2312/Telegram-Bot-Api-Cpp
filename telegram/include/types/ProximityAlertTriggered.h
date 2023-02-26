#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
#include "User.h"
//This object represents the content of a service message, sent whenever a user in the chat triggers a proximity alert set by another user.
struct ProximityAlertTriggered{
	std::shared_ptr<User> traveler;
	std::shared_ptr<User> watcher;
	int distance;
};

