#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "LabeledPrice.h"
//This object represents one shipping option.
struct ShippingOption{
	std::string id;
	std::string title;
	std::vector<std::shared_ptr<LabeledPrice>> prices;
};

