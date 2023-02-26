#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "MessageEntity.h"
//This object represents the content of a media message to be sent. It should be one of
struct InputMedia{
	std::string type;
	std::string media;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool has_spoiler;
};

