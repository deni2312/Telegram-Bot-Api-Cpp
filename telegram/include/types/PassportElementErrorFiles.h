#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents an issue with a list of scans. The error is considered resolved when the list of files containing the scans changes.
struct PassportElementErrorFiles{
	std::string source;
	std::string type;
	std::string file_hashes;
	std::string message;
};

