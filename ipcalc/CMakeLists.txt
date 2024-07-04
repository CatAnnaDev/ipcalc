cmake_minimum_required(VERSION 3.27)
project(ipcalc C)

set(CMAKE_C_STANDARD 23)

add_executable(ipcalc main.c
        valide_ip.c
        valid_ip.h
        calc_ip.c
        calc_ip.h)
