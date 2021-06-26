cmake_minimum_required(VERSION 3.8.0)


project(TelegramBotApiCpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(TelegramBotApiCpp telegram/main.cpp telegram/src/TelegramAPI.cpp telegram/src/types.cpp "telegram/include/network/HTTPrequest.h" "telegram/src/network/HTTPrequest.cpp" "telegram/include/network/Error.h" "telegram/src/network/Error.cpp" "telegram/include/network/Network.h")
find_package(cpr CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
if (MSVC)
    find_package(jsoncpp CONFIG REQUIRED)
    find_package(CURL CONFIG REQUIRED)
    target_link_libraries(TelegramBotApiCpp PRIVATE jsoncpp_lib jsoncpp_object cpr)
endif (MSVC)
if (UNIX)
    target_link_libraries( TelegramBotApiCpp curl pthread jsoncpp cpr)
endif (UNIX)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
