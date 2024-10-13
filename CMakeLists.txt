cmake_minimum_required(VERSION 3.29)
project(Number_Tests)

set(CMAKE_CXX_STANDARD 26)

add_executable(Number_Tests main.cpp
        SoloveyShtrassen.cpp
        SoloveyShtrassen.h
        number.h
        RabenMiller.cpp
        RabenMiller.h
        helpers.cpp
        helpers.h)
