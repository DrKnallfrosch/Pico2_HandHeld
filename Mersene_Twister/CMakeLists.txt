cmake_minimum_required(VERSION 3.30)
project(Mersene_Twister C)

set(CMAKE_C_STANDARD 11)

add_library(Mersene_Twister STATIC MT19937.c)
