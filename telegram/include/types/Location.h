#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a point on the map.
struct Location{
	float longitude;
	float latitude;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
};

