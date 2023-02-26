#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "LabeledPrice.h"
//Represents the <a href="#inputmessagecontent">content</a> of an invoice message to be sent as the result of an inline query.
struct InputInvoiceMessageContent{
	std::string title;
	std::string description;
	std::string payload;
	std::string provider_token;
	std::string currency;
	std::vector<std::shared_ptr<LabeledPrice>> prices;
	int max_tip_amount;
	int suggested_tip_amounts;
	std::string provider_data;
	std::string photo_url;
	int photo_size;
	int photo_width;
	int photo_height;
	bool need_name;
	bool need_phone_number;
	bool need_email;
	bool need_shipping_address;
	bool send_phone_number_to_provider;
	bool send_email_to_provider;
	bool is_flexible;
};

