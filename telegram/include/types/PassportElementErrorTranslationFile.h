#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents an issue with one of the files that constitute the translation of a document. The error is considered resolved when the file changes.
struct PassportElementErrorTranslationFile{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

