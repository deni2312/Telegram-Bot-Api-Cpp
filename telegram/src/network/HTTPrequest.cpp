#include "../../include/network/HTTPrequest.h"
#include <nlohmann/json.hpp>

Telegram::Bot::Types::HTTPrequest::HTTPrequest(const std::string &link) : link{link} {

}

const std::string
Telegram::Bot::Types::HTTPrequest::sendHttp(const std::string &query, const std::string &body, bool json) {
    std::string response = "";
    if (json) {
        response = cpr::Post(cpr::Url{link + query},
                             cpr::Body{body},
                             cpr::Header{{"Content-Type", "application/json"}}).text;
    } else {
        response = cpr::Post(cpr::Url{link + query + body}).text;
    }
    if (response.find("\"ok\":false") != std::string::npos) {
        throw Telegram::Bot::Types::Error(response);
    }
    return response;
}

const std::string
Telegram::Bot::Types::HTTPrequest::sendFile(const std::string &query, const std::string &body, const MediaType &type,
                                            const std::string &path,
                                            const std::string &thumb, const std::string &thumbpath) {
    std::string r;
    std::string type_string;
    std::map<MediaType, std::string> stringToMedia{
            {PHOTO,    "photo"},
            {VIDEO,    "video"},
            {DOCUMENT, "document"},
            {AUDIO,    "audio"}
    };
    nlohmann::json j = nlohmann::json::parse(body);
    cpr::Multipart part{};
    // Iterate over the JSON object
    for (auto it = j.begin(); it != j.end(); ++it) {
        // Check if the current element is an object
        if (!it.value().is_string()) {
            part.parts.push_back({it.key().c_str(), to_string(it.value())});
        } else {
            part.parts.push_back({it.key().c_str(), (std::string) it.value()});
        }
    }
    part.parts.push_back({stringToMedia[type], cpr::File{path}});
    if (thumb != "") {
        r = cpr::Get(cpr::Url{link + query}, cpr::Body{body}, cpr::Header{{"Content-Type", "application/json"}},
                     cpr::Multipart{{stringToMedia[type] + "=", "1"},
                                    {stringToMedia[type],       cpr::File{path}},
                                    {thumb + "=",               "1"},
                                    {thumb,                     cpr::File{thumbpath}}}).text;
    } else {
        r = cpr::Get(cpr::Url{link + query},
                     part).text;
    }
    if (r.find("\"ok\":false") != std::string::npos) {
        throw Telegram::Bot::Types::Error(r);
    }
    return r;
}

const std::string Telegram::Bot::Types::HTTPrequest::sendMultiFile(const std::string &query, const std::string &type,
                                                                   const std::vector<std::string> &paths) {
    std::string r;
    cpr::Multipart multi{};
    for (int i = 0; i < paths.size(); i++) {
        multi.parts.push_back({type + "=", std::to_string(i)});
        multi.parts.push_back({type, cpr::File{paths.at(i)}});
    }
    r = cpr::Get(cpr::Url{link + query},
                 multi).text;

    if (r.find("\"ok\":false") != std::string::npos) {
        throw Telegram::Bot::Types::Error(r);
    }
    return r;
    return std::string();
}

Telegram::Bot::Types::HTTPrequest::~HTTPrequest() {

}
