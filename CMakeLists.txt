cmake_minimum_required(VERSION 3.12)
project(tetris_game)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_C_FLAGS "-std=c11 -Wall -pedantic-errors -Werror -Wno-unused")

#Bring the headers into the project
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
