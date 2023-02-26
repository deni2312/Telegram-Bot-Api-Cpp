#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "KeyboardButtonRequestUser.h"
#include "KeyboardButtonRequestChat.h"
#include "KeyboardButtonPollType.h"
#include "WebAppInfo.h"
//This object represents one button of the reply keyboard. For simple text buttons, <em>String</em> can be used instead of this object to specify the button text. The optional fields <em>web_app</em>, <em>request_user</em>, <em>request_chat</em>, <em>request_contact</em>, <em>request_location</em>, and <em>request_poll</em> are mutually exclusive.
struct KeyboardButton{
	std::string text;
	std::shared_ptr<KeyboardButtonRequestUser> request_user;
	std::shared_ptr<KeyboardButtonRequestChat> request_chat;
	bool request_contact;
	bool request_location;
	std::shared_ptr<KeyboardButtonPollType> request_poll;
	std::shared_ptr<WebAppInfo> web_app;
};

