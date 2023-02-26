#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InputFile.h"
#include "MessageEntity.h"
//Represents a video to be sent.
struct InputMediaVideo{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	int width;
	int height;
	int duration;
	bool supports_streaming;
	bool has_spoiler;
};

