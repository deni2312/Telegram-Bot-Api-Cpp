#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//This object represents one row of the high scores table for a game.
struct GameHighScore{
	int position;
	std::shared_ptr<User> user;
	int score;
};

