#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents the rights of an administrator in a chat.
struct ChatAdministratorRights{
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
};

