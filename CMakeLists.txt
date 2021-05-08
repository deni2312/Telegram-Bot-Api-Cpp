cmake_minimum_required(VERSION 3.0.0)
project(TelegramBotApiCpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(TelegramBotApiCpp linux/main.cpp linux/src/TelegramAPI.cpp linux/src/types.cpp)

target_link_libraries( TelegramBotApiCpp curl pthread jsoncpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
