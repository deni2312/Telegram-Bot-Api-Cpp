#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a phone contact.
struct Contact{
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	int user_id;
	std::string vcard;
};

