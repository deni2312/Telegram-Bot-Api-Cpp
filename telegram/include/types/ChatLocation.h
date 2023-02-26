#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "Location.h"
//Represents a location to which a chat is connected.
struct ChatLocation{
	std::shared_ptr<Location> location;
	std::string address;
};

