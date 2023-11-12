cmake_minimum_required(VERSION 3.26)
project(Lista_De_Tarefas C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lista_De_Tarefas
        biblioteca.c
        biblioteca.h
        main.c
        biblioteca_aux.c)
