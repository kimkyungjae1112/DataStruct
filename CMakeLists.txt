cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME DataStruct)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} 
   src/main.cpp
)
