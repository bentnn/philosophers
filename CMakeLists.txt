cmake_minimum_required(VERSION 3.19)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers philo/main.c philo/simple_func.c philo/philo.h philo/data_func.c philo/simple_func2.c philo/routines.c)