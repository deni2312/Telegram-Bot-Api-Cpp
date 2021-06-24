#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "Error.h"
#include <cpr/cpr.h>
#ifdef _WIN32
#include <json/json.h>
#else
#include <jsoncpp/json/json.h>
#endif

class HTTPrequest {
public:
	HTTPrequest(const std::string& link);
	HTTPrequest() = delete;
	HTTPrequest& operator=(const HTTPrequest& connector) = delete;
	const Json::Value sendHttp(const std::string& query);
	const std::string sendFile(const std::string& query,const std::string& type,const std::string& path,const std::string& thumb="",const std::string& thumbpath="");
	const std::string sendMultiFile(const std::string& query, const std::string& type, const std::vector<std::string>& paths);
	~HTTPrequest();
private:
	const std::string link;
};