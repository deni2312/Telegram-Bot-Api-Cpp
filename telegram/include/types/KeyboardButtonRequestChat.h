#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "ChatAdministratorRights.h"
#include "ChatAdministratorRights.h"
//This object defines the criteria used to request a suitable chat. The identifier of the selected chat will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestChat{
	int request_id;
	bool chat_is_channel;
	bool chat_is_forum;
	bool chat_has_username;
	bool chat_is_created;
	std::shared_ptr<ChatAdministratorRights> user_administrator_rights;
	std::shared_ptr<ChatAdministratorRights> bot_administrator_rights;
	bool bot_is_member;
};

