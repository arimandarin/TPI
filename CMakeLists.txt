cmake_minimum_required(VERSION 3.23)
project(tpi2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")


set(SOURCE_FILES
        main.cpp
        ejercicios.cpp
        ejercicios.h
        definiciones.h
        auxiliares.cpp
        auxiliares.h)

add_executable(tpi2 ${SOURCE_FILES} ${DIR_TESTS})

