#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents an animated emoji that displays a random value.
struct Dice{
	std::string emoji;
	int value;
};

