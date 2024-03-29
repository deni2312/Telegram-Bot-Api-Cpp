#pragma once

#include <memory>
#include <iostream>
#include "Error.h"
#include "Network.h"
#include <cpr/cpr.h>

namespace Telegram {
    namespace Bot {
        namespace Types {
            class HTTPrequest : public Network {
            public:
                HTTPrequest(const std::string &link);

                HTTPrequest() = delete;

                HTTPrequest &operator=(const HTTPrequest &connector) = delete;

                const std::string sendHttp(const std::string &query, const std::string &body, bool json = true);

                const std::string sendFile(const std::string &query, const std::string &body, const MediaType &type,
                                           const std::string &path = "",
                                           const std::string &thumb = "", const std::string &thumbpath = "");

                const std::string
                sendMultiFile(const std::string &query, const std::string &type, const std::vector<std::string> &paths);

                ~HTTPrequest();

            private:
                const std::string link;
            };
        }
    }
}