#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "ShippingAddress.h"
//This object represents information about an order.
struct OrderInfo{
	std::string name;
	std::string phone_number;
	std::string email;
	std::shared_ptr<ShippingAddress> shipping_address;
};

