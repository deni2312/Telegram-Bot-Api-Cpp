#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object contains information about one answer option in a poll.
struct PollOption{
	std::string text;
	int voter_count;
};

