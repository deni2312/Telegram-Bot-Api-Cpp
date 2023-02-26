#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object contains information about the user whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestuser">KeyboardButtonRequestUser</a> button.
struct UserShared{
	int request_id;
	int user_id;
};

