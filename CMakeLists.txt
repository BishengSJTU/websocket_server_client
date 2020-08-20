cmake_minimum_required(VERSION 3.5)
project(websocket)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED filesystem program_options regex timer chrono)

set(WS_DIR /usr/local/include/websocketpp)

include_directories(include ${WS_DIR})

add_executable(client client.cpp)
add_executable(server server.cpp)

target_link_libraries(client pthread boost_system)
target_link_libraries(server pthread boost_system)
