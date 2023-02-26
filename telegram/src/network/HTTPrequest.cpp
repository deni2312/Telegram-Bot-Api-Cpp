#include "../../include/network/HTTPrequest.h"

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
    std::map<MediaType, std::string> stringToFruit{
            {PHOTO,    "photo"},
            {VIDEO,    "video"},
            {DOCUMENT, "document"},
    };
    if (thumb != "") {
        r = cpr::Get(cpr::Url{link + query}, cpr::Body{body},
                     cpr::Multipart{{stringToFruit[type] + "=", "1"},
                                    {stringToFruit[type],       cpr::File{path}},
                                    {thumb + "=",               "1"},
                                    {thumb,                     cpr::File{thumbpath}}}).text;
    } else {
        r = cpr::Get(cpr::Url{link + query},
                     cpr::Multipart{{stringToFruit[type] + "=", "1"},
                                    {stringToFruit[type],       cpr::File{path}}}).text;
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
