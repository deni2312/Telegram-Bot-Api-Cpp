#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InputFile.h"
#include "MessageEntity.h"
//Represents an audio file to be treated as music to be sent.
struct InputMediaAudio{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	int duration;
	std::string performer;
	std::string title;
};

