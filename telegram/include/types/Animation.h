#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PhotoSize.h"
//This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
struct Animation{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	std::shared_ptr<PhotoSize> thumb;
	std::string file_name;
	std::string mime_type;
	int file_size;
};

