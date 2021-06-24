#include <string>
#include <exception>
namespace Telegram {
	namespace Bot {
		namespace Types {
			struct Error : public std::exception {
				Error(std::string error);
				const char* what() const noexcept override;
			private:
				std::string message;
			};
		}
	}
}