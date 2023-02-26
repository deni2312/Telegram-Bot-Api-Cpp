#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "User.h"
#include "OrderInfo.h"
//This object contains information about an incoming pre-checkout query.
struct PreCheckoutQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string currency;
	int total_amount;
	std::string invoice_payload;
	std::string shipping_option_id;
	std::shared_ptr<OrderInfo> order_info;
};

