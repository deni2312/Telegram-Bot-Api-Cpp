#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PhotoSize.h"
//This object represent a user&#39;s profile pictures.
struct UserProfilePhotos{
	int total_count;
	std::vector<std::shared_ptr<PhotoSize>> photos;
};

