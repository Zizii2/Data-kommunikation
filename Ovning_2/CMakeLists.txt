cmake_minimum_required(VERSION 3.10.0)
project(tcp_make VERSION 0.1.0 LANGUAGES C CXX)

add_executable(tcp_client client.cpp)
add_executable(tcp_server server.cpp)

include(CTest)
enable_testing()

