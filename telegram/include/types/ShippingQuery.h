#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
#include "ShippingAddress.h"
//This object contains information about an incoming shipping query.
struct ShippingQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string invoice_payload;
	std::shared_ptr<ShippingAddress> shipping_address;
};

