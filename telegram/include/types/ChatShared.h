#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object contains information about the chat whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestchat">KeyboardButtonRequestChat</a> button.
struct ChatShared{
	int request_id;
	int chat_id;
};

