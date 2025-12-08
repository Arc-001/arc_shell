cmake_minimum_required(VERSION 4.1)
project(arc_shell C)

set(CMAKE_C_STANDARD 11)

add_executable(arc_shell
        main.c
        io.h
        io.c
        parser.c
        parser.c
        parser.c)
