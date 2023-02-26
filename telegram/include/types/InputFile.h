#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "MessageEntity.h"
#include "InlineKeyboardMarkup.h"
//This object represents the contents of a file to be uploaded. Must be posted using multipart/form-data in the usual way that files are uploaded via the browser.
struct InputFile{
	int chat_id;
	int message_thread_id;
	std::string text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
	bool disable_notification;
	bool protect_content;
	int reply_to_message_id;
	bool allow_sending_without_reply;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
};

