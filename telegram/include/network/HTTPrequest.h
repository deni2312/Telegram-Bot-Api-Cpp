#pragma once
#include <curl/curl.h>
#include <string>
#include <memory>
#include <iostream>
#include "../types.h"

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
	typedef void(*cleanup)(void* c);
	typedef std::unique_ptr<CURL, cleanup> handle;
	handle curl;
	CURLcode res;
};