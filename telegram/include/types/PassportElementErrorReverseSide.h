#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents an issue with the reverse side of a document. The error is considered resolved when the file with reverse side of the document changes.
struct PassportElementErrorReverseSide{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

