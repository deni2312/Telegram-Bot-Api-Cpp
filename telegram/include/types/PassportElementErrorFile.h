#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents an issue with a document scan. The error is considered resolved when the file with the document scan changes.
struct PassportElementErrorFile{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

