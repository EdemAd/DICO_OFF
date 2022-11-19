cmake_minimum_required(VERSION 3.21)
project(DICO_OFF C)

set(CMAKE_C_STANDARD 99)

add_executable(DICO_OFF main.c word.c word.h list_cell.c list_cell.h)
