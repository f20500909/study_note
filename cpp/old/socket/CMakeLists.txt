cmake_minimum_required(VERSION 3.0)
project(server)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
add_executable(server server.cpp "../blog/shu_chuang.cpp")
