cmake_minimum_required(VERSION 3.29)
project(cs454project1)
set(CMAKE_CXX_STANDARD 20)

add_executable(cs454project1 main.cpp
        DFA.hpp
        Buffer.cpp
        Buffer.hpp
        DFA.cpp)

target_include_directories(cs454project1 PRIVATE /opt/homebrew/include)
target_link_directories(cs454project1 PRIVATE /opt/homebrew/lib)
target_link_libraries(cs454project1 PRIVATE gmpxx gmp)

