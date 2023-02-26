#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "WebAppInfo.h"
#include "LoginUrl.h"
#include "CallbackGame.h"
//This object represents one button of an inline keyboard. You <strong>must</strong> use exactly one of the optional fields.
struct InlineKeyboardButton{
	std::string text;
	std::string url;
	std::string callback_data;
	std::shared_ptr<WebAppInfo> web_app;
	std::shared_ptr<LoginUrl> login_url;
	std::string switch_inline_query;
	std::string switch_inline_query_current_chat;
	std::shared_ptr<CallbackGame> callback_game;
	bool pay;
};

