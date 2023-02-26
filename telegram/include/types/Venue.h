#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "Location.h"
//This object represents a venue.
struct Venue{
	std::shared_ptr<Location> location;
	std::string title;
	std::string address;
	std::string foursquare_id;
	std::string foursquare_type;
	std::string google_place_id;
	std::string google_place_type;
};

