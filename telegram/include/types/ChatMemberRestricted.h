#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
//Represents a <a href="#chatmember">chat member</a> that is under certain restrictions in the chat. Supergroups only.
struct ChatMemberRestricted{
	std::string status;
	std::shared_ptr<User> user;
	bool is_member;
	bool can_send_messages;
	bool can_send_audios;
	bool can_send_documents;
	bool can_send_photos;
	bool can_send_videos;
	bool can_send_video_notes;
	bool can_send_voice_notes;
	bool can_send_polls;
	bool can_send_other_messages;
	bool can_add_web_page_previews;
	bool can_change_info;
	bool can_invite_users;
	bool can_pin_messages;
	bool can_manage_topics;
	int until_date;
};

