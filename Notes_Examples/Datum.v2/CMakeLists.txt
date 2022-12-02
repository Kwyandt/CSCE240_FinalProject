cmake_minimum_required(VERSION 3.23)
project(Datum_v2)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Datum_v2
        Datum.cpp
        Datum.h
        main1.cpp)
