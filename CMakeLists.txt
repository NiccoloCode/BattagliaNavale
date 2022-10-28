cmake_minimum_required(VERSION 3.23)
project(BattagliaNavale)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattagliaNavale main.cpp ship.cpp ship.h game.h game.cpp)
