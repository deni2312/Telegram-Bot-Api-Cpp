#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents type of a poll, which is allowed to be created and sent when the corresponding button is pressed.
struct KeyboardButtonPollType{
	std::string type;
};

