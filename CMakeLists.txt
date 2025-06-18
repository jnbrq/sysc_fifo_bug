cmake_minimum_required(VERSION 3.28)
project(sysc_tb)

find_package(SystemCLanguage REQUIRED)

include(CMakeParseArguments)

add_executable(sysc_fifo_bug src/main.cpp)
target_link_libraries(sysc_fifo_bug PUBLIC SystemC::systemc)
