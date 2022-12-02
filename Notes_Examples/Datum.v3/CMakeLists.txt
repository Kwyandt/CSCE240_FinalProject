cmake_minimum_required(VERSION 3.23)
project(Datum_v3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Datum_v3
        Datum.cpp
        Datum.h
        main.cpp)
