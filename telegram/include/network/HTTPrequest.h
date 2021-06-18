#pragma once
#include <curl/curl.h>
#include <string>
#include <memory>
#include <iostream>

class HTTPrequest {
public:
	HTTPrequest(const std::string& link);
	HTTPrequest() = delete;
	HTTPrequest& operator=(const HTTPrequest& connector) = delete;
	const std::string sendHttp(const std::string& query);
	const std::string sendFile(const std::string& query);
	~HTTPrequest();
private:
	const std::string link;
	CURL* curl;
	CURLcode res;
};