#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Represents the <a href="#inputmessagecontent">content</a> of a venue message to be sent as the result of an inline query.
struct InputVenueMessageContent{
	float latitude;
	float longitude;
	std::string title;
	std::string address;
	std::string foursquare_id;
	std::string foursquare_type;
	std::string google_place_id;
	std::string google_place_type;
};

