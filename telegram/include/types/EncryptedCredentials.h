#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//Describes data required for decrypting and authenticating <a href="#encryptedpassportelement">EncryptedPassportElement</a>. See the <a href="/passport#receiving-information">Telegram Passport Documentation</a> for a complete description of the data decryption and authentication processes.
struct EncryptedCredentials{
	std::string data;
	std::string hash;
	std::string secret;
};

