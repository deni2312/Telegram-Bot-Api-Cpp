#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "ChatPhoto.h"
#include "Message.h"
#include "ChatPermissions.h"
#include "ChatLocation.h"
//This object represents a chat.
struct Chat{
	int id;
	std::string type;
	std::string title;
	std::string username;
	std::string first_name;
	std::string last_name;
	bool is_forum;
	std::shared_ptr<ChatPhoto> photo;
	std::string active_usernames;
	std::string emoji_status_custom_emoji_id;
	std::string bio;
	bool has_private_forwards;
	bool has_restricted_voice_and_video_messages;
	bool join_to_send_messages;
	bool join_by_request;
	std::string description;
	std::string invite_link;
	std::shared_ptr<Message> pinned_message;
	std::shared_ptr<ChatPermissions> permissions;
	int slow_mode_delay;
	int message_auto_delete_time;
	bool has_aggressive_anti_spam_enabled;
	bool has_hidden_members;
	bool has_protected_content;
	std::string sticker_set_name;
	bool can_set_sticker_set;
	int linked_chat_id;
	std::shared_ptr<ChatLocation> location;
};

