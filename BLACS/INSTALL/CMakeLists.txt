cmake_minimum_required(VERSION 3.2)
project(INSTALL LANGUAGES C Fortran)

add_library(c_obj OBJECT Cintface.c)

add_executable(xintface Fintface.f $<TARGET_OBJECTS:c_obj>)
