#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents an error in the Telegram Passport element which was submitted that should be resolved by the user. It should be one of:
struct PassportElementError{
	std::string source;
	std::string type;
	std::string field_name;
	std::string data_hash;
	std::string message;
};

