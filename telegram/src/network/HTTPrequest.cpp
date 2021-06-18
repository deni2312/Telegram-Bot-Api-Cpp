#include "..\..\include\network\HTTPrequest.h"

HTTPrequest::HTTPrequest(const std::string& link):link{link}
{
	curl = curl_easy_init();
}

inline size_t WriteaCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

const std::string HTTPrequest::sendHttp(const std::string& query)
{
	std::string l;
	std::string readBuffer;
	l = link + query;
	curl_easy_setopt(curl, CURLOPT_URL, l.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteaCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	res = curl_easy_perform(curl);
	return readBuffer;
}

const std::string HTTPrequest::sendFile(const std::string& query)
{
	return "";
}

HTTPrequest::~HTTPrequest()
{
	curl_easy_cleanup(curl);
}
