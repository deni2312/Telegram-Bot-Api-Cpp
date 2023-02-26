#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a service message about a change in auto-delete timer settings.
struct MessageAutoDeleteTimerChanged{
	int message_auto_delete_time;
};

