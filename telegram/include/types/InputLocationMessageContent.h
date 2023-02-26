#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents the <a href="#inputmessagecontent">content</a> of a location message to be sent as the result of an inline query.
struct InputLocationMessageContent{
	float latitude;
	float longitude;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
};

