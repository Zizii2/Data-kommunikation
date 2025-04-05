cmake_minimum_required(VERSION 3.10.0)
project(chat_room VERSION 0.1.0 LANGUAGES C CXX)

add_executable(server_build src/server.cpp)
add_executable(client_build src/client.cpp)

include(CTest)
enable_testing()

