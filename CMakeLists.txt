cmake_minimum_required(VERSION 3.10)
# set the project name
project(Kontaktanalyse)

set(CMAKE_C_FLAGS "-std=c99")

add_executable(generator generator.c)
