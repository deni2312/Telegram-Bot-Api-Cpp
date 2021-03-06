#pragma once
#include <string>
#include <vector>
#ifdef _WIN32
#include <json/json.h>
#else
#include <jsoncpp/json/json.h>
#endif
namespace Telegram {
	namespace Bot {
		namespace Types {
			class Network {
			public:
				const virtual Json::Value sendHttp(const std::string& query) = 0;
				const virtual std::string sendFile(const std::string& query, const std::string& type, const std::string& path, const std::string& thumb = "", const std::string& thumbpath = "") = 0;
				const virtual std::string sendMultiFile(const std::string& query, const std::string& type, const std::vector<std::string>& paths) = 0;
			};
		}
	}
}