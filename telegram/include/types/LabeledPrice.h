#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a portion of the price for goods or services.
struct LabeledPrice{
	std::string label;
	int amount;
};

