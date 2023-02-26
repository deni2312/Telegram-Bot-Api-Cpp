#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a Telegram user or bot.
struct User{
	int id;
	bool is_bot;
	std::string first_name;
	std::string last_name;
	std::string username;
	std::string language_code;
	bool is_premium;
	bool added_to_attachment_menu;
	bool can_join_groups;
	bool can_read_all_group_messages;
	bool supports_inline_queries;
};

