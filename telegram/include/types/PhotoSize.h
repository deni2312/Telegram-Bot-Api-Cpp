#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents one size of a photo or a <a href="#document">file</a> / <a href="#sticker">sticker</a> thumbnail.
struct PhotoSize{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int file_size;
};

