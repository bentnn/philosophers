cmake_minimum_required(VERSION 3.19)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers srcs/main.c srcs/simple_func.c srcs/philo.h srcs/data_func.c srcs/simple_func2.c srcs/routines.c srcs/simple_func3.c)