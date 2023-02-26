#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//Represents a <a href="#chatmember">chat member</a> that has some additional privileges.
struct ChatMemberAdministrator{
	std::string status;
	std::shared_ptr<User> user;
	bool can_be_edited;
	bool is_anonymous;
	bool can_manage_chat;
	bool can_delete_messages;
	bool can_manage_video_chats;
	bool can_restrict_members;
	bool can_promote_members;
	bool can_change_info;
	bool can_invite_users;
	bool can_post_messages;
	bool can_edit_messages;
	bool can_pin_messages;
	bool can_manage_topics;
	std::string custom_title;
};

