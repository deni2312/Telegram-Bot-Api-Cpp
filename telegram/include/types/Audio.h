#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PhotoSize.h"
//This object represents an audio file to be treated as music by the Telegram clients.
struct Audio{
	std::string file_id;
	std::string file_unique_id;
	int duration;
	std::string performer;
	std::string title;
	std::string file_name;
	std::string mime_type;
	int file_size;
	std::shared_ptr<PhotoSize> thumb;
};

