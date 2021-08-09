#include "../../include/network/HTTPrequest.h"

Telegram::Bot::Types::HTTPrequest::HTTPrequest(const std::string& link) :link{ link }
{
	
}

const Json::Value Telegram::Bot::Types::HTTPrequest::sendHttp(const std::string& query)
{
	std::string r;
	r = cpr::Get(cpr::Url{ link + query }).text;
	if (r.find("\"ok\":false") != std::string::npos) {
		throw Telegram::Bot::Types::Error(r);
	}
	return r;
}

const std::string Telegram::Bot::Types::HTTPrequest::sendFile(const std::string& query,const std::string& type,const std::string& path,const std::string& thumb,const std::string& thumbpath)
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

const std::string Telegram::Bot::Types::HTTPrequest::sendMultiFile(const std::string& query,const std::string& type, const std::vector<std::string>& paths)
{
	std::string r;
	cpr::Multipart multi{};
	for (int i = 0; i < paths.size(); i++) {
		multi.parts.push_back({ type + "=",std::to_string(i) });
		multi.parts.push_back({ type ,cpr::File{paths.at(i)} });
	}
	r = cpr::Get(cpr::Url{ link + query },
	multi).text;
	
	if (r.find("\"ok\":false") != std::string::npos) {
		throw Telegram::Bot::Types::Error(r);
	}
	return r;
	return std::string();
}

Telegram::Bot::Types::HTTPrequest::~HTTPrequest()
{
	
}
