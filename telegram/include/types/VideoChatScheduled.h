#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a service message about a video chat scheduled in the chat.
struct VideoChatScheduled{
	int start_date;
};

