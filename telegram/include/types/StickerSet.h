#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "Sticker.h"
#include "PhotoSize.h"
//This object represents a sticker set.
struct StickerSet{
	std::string name;
	std::string title;
	std::string sticker_type;
	bool is_animated;
	bool is_video;
	std::vector<std::shared_ptr<Sticker>> stickers;
	std::shared_ptr<PhotoSize> thumb;
};

