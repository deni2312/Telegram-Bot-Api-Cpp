#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot&#39;s message and tapped &#39;Reply&#39;). This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice <a href="/bots/features#privacy-mode">privacy mode</a>.
struct ForceReply{
};

