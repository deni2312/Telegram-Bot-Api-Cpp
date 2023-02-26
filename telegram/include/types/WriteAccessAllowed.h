#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object represents a service message about a user allowing a bot added to the attachment menu to write messages. Currently holds no information.
struct WriteAccessAllowed{
};

