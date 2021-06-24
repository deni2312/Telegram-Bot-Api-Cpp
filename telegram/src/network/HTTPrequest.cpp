#include "..\..\include\network\HTTPrequest.h"

HTTPrequest::HTTPrequest(const std::string& link) :link{ link }
{
	
}

const Json::Value HTTPrequest::sendHttp(const std::string& query)
{
	std::string r;
	r = cpr::Get(cpr::Url{ link + query }).text;
	if (r.find("\"ok\":false") != std::string::npos) {
		throw Telegram::Bot::Types::Error(r);
	}
	return r;
}

const std::string HTTPrequest::sendFile(const std::string& query,const std::string& type,const std::string& path,const std::string& thumb,const std::string& thumbpath)
{
	std::string r;
	if (thumb != "") {
		r = cpr::Get(cpr::Url{ link + query },
			cpr::Multipart{ {type + "=", "1"} ,{type,cpr::File{path}} ,{thumb + "=","1"},{thumb,cpr::File{thumbpath}} }).text;
	}
	else {
		r = cpr::Get(cpr::Url{ link + query },
			cpr::Multipart{ {type + "=", "1"} ,{type,cpr::File{path}} }).text;
	}
	if (r.find("\"ok\":false") != std::string::npos) {
		throw Telegram::Bot::Types::Error(r);
	}
	return r;
}

HTTPrequest::~HTTPrequest()
{
	
}
