#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include "PassportFile.h"
#include "PassportFile.h"
#include "PassportFile.h"
#include "PassportFile.h"
#include "PassportFile.h"
//Describes documents or other Telegram Passport elements shared with the bot by the user.
struct EncryptedPassportElement{
	std::string type;
	std::string data;
	std::string phone_number;
	std::string email;
	std::vector<std::shared_ptr<PassportFile>> files;
	std::shared_ptr<PassportFile> front_side;
	std::shared_ptr<PassportFile> reverse_side;
	std::shared_ptr<PassportFile> selfie;
	std::vector<std::shared_ptr<PassportFile>> translation;
	std::string hash;
};

