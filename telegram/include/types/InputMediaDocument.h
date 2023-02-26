#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "InputFile.h"
#include "MessageEntity.h"
//Represents a general file to be sent.
struct InputMediaDocument{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool disable_content_type_detection;
};

