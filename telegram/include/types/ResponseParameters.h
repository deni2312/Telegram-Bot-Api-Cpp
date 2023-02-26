#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Describes why a request was unsuccessful.
struct ResponseParameters{
	int migrate_to_chat_id;
	int retry_after;
};

