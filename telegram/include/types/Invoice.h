#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object contains basic information about an invoice.
struct Invoice{
	std::string title;
	std::string description;
	std::string start_parameter;
	std::string currency;
	int total_amount;
};

