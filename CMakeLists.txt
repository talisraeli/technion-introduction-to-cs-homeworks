cmake_minimum_required(VERSION 4.0)
project(Homeworks C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic-errors -lm -g")

add_executable(hw0q1 hw0/hw0q1.c)

add_executable(hw1q1 hw1/hw1q1.c)
add_executable(hw1q2 hw1/hw1q2.c)
add_executable(hw1q3 hw1/hw1q3.c)

add_executable(hw2q1 hw2/hw2q1.c)
add_executable(hw2q2 hw2/hw2q2.c)
