#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "Chat.h"
#include "User.h"
#include "ChatInviteLink.h"
//Represents a join request sent to a chat.
struct ChatJoinRequest{
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> from;
	int user_chat_id;
	int date;
	std::string bio;
	std::shared_ptr<ChatInviteLink> invite_link;
};

