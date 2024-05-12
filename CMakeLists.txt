cmake_minimum_required(VERSION 3.27)
project(Supermarket_Product_Management_System C)

set(CMAKE_C_STANDARD 11)

add_executable(Supermarket_Product_Management_System
        src/Supermarket_Product_Management_System.c
        include/Product_Management_System.h
)
