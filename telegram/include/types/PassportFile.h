#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a file uploaded to Telegram Passport. Currently all Telegram Passport files are in JPEG format when decrypted and don&#39;t exceed 10MB.
struct PassportFile{
	std::string file_id;
	std::string file_unique_id;
	int file_size;
	int file_date;
};

