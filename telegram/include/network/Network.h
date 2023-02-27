#pragma once

#include <string>
#include <vector>

namespace Telegram {
    enum MediaType {
        PHOTO, VIDEO, DOCUMENT, AUDIO
    };
    enum MediaSource {
        LOCAL, SERVER
    };
    namespace Bot {
        namespace Types {
            class Network {
            public:
                const virtual std::string
                sendHttp(const std::string &query, const std::string &body, bool json = true) = 0;

                const virtual std::string
                sendFile(const std::string &query, const std::string &body, const MediaType &type,
                         const std::string &path = "",
                         const std::string &thumb = "", const std::string &thumbpath = "") = 0;

                const virtual std::string sendMultiFile(const std::string &query, const std::string &type,
                                                        const std::vector<std::string> &paths) = 0;
            };
        }
    }
}
