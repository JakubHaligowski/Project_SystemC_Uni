cmake_minimum_required(VERSION 3.0)

project(FirstSystemCProject)

set(SYSTEMC_INCLUDE_DIR $ENV{SYSTEMC_HOME}/include)
set(SYSTEMC_LIBRARY_DIR $ENV{SYSTEMC_HOME}/lib)

add_executable(systemC_project main.cpp SecondModule.hpp SecondModule.cpp NestedModule.hpp NestedModule.cpp FirstModule.hpp FirstModule.cpp)

target_include_directories(systemC_project PRIVATE ${SYSTEMC_INCLUDE_DIR})
target_link_libraries(systemC_project ${SYSTEMC_LIBRARY_DIR}/libsystemc.so)
