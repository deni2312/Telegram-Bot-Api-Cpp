#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "Chat.h"
#include "User.h"
#include "ChatMember.h"
#include "ChatMember.h"
#include "ChatInviteLink.h"
//This object represents changes in the status of a chat member.
struct ChatMemberUpdated{
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> from;
	int date;
	std::shared_ptr<ChatMember> old_chat_member;
	std::shared_ptr<ChatMember> new_chat_member;
	std::shared_ptr<ChatInviteLink> invite_link;
};

