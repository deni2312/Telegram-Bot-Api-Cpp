#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents an issue in an unspecified place. The error is considered resolved when new data is added.
struct PassportElementErrorUnspecified{
	std::string source;
	std::string type;
	std::string element_hash;
	std::string message;
};

