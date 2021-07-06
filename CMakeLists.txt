cmake_minimum_required(VERSION 3.19)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers main.c simple_func.c philo.h data_func.c simple_func2.c)