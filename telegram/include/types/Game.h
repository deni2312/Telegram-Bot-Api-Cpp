#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PhotoSize.h"
#include "MessageEntity.h"
#include "Animation.h"
//This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
struct Game{
	std::string title;
	std::string description;
	std::vector<std::shared_ptr<PhotoSize>> photo;
	std::string text;
	std::vector<std::shared_ptr<MessageEntity>> text_entities;
	std::shared_ptr<Animation> animation;
};

