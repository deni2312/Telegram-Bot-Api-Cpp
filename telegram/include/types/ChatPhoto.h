#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a chat photo.
struct ChatPhoto{
	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
};

