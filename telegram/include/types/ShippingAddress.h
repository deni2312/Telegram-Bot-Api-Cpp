#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a shipping address.
struct ShippingAddress{
	std::string country_code;
	std::string state;
	std::string city;
	std::string street_line1;
	std::string street_line2;
	std::string post_code;
};

