#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PhotoSize.h"
#include "File.h"
#include "MaskPosition.h"
//This object represents a sticker.
struct Sticker{
	std::string file_id;
	std::string file_unique_id;
	std::string type;
	int width;
	int height;
	bool is_animated;
	bool is_video;
	std::shared_ptr<PhotoSize> thumb;
	std::string emoji;
	std::string set_name;
	std::shared_ptr<File> premium_animation;
	std::shared_ptr<MaskPosition> mask_position;
	std::string custom_emoji_id;
	int file_size;
};

