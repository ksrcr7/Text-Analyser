cmake_minimum_required(VERSION 3.27)
project(Text_Analyser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Text_Analyser src/main.cpp
        "include/TextAnalyser.h"
        include/CLI.h
        "src/TextAnalyser.cpp"
        src/CLI.cpp)
