cmake_minimum_required(VERSION 3.20)
project(c_asm C)

set(CMAKE_C_STANDARD 11)

add_executable(c_asm main.c rnd.h rnd.c container.h container.c language.h language.c OOP.h OOP.c procedure.h
        procedure.c functional.h functional.c commonFunction.asm)
