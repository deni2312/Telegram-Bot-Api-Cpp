#include "../../include/network/Error.h"
Telegram::Bot::Types::Error::Error(std::string error) :message{ error }
{
}

const char* Telegram::Bot::Types::Error::what() const noexcept
{
	return message.c_str();
}