#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PollOption.h"
#include "MessageEntity.h"
//This object contains information about a poll.
struct Poll{
	std::string id;
	std::string question;
	std::vector<std::shared_ptr<PollOption>> options;
	int total_voter_count;
	bool is_closed;
	bool is_anonymous;
	std::string type;
	bool allows_multiple_answers;
	int correct_option_id;
	std::string explanation;
	std::vector<std::shared_ptr<MessageEntity>> explanation_entities;
	int open_period;
	int close_date;
};

