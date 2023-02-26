#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a voice note.
struct Voice{
	std::string file_id;
	std::string file_unique_id;
	int duration;
	std::string mime_type;
	int file_size;
};

