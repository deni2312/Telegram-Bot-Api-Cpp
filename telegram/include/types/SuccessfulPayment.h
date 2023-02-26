#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "OrderInfo.h"
//This object contains basic information about a successful payment.
struct SuccessfulPayment{
	std::string currency;
	int total_amount;
	std::string invoice_payload;
	std::string shipping_option_id;
	std::shared_ptr<OrderInfo> order_info;
	std::string telegram_payment_charge_id;
	std::string provider_payment_charge_id;
};

