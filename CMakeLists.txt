cmake_minimum_required(VERSION 3.28)
project(oatpp_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(oatpp_test main.cpp
        Traceroute.cpp
        Traceroute.h)

find_package(oatpp 1.3.0 REQUIRED)
