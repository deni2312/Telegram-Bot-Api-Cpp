#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object defines the criteria used to request a suitable user. The identifier of the selected user will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestUser{
	int request_id;
	bool user_is_bot;
	bool user_is_premium;
};

