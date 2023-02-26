#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "EncryptedPassportElement.h"
#include "EncryptedCredentials.h"
//Describes Telegram Passport data shared with the bot by the user.
struct PassportData{
	std::vector<std::shared_ptr<EncryptedPassportElement>> data;
	std::shared_ptr<EncryptedCredentials> credentials;
};

