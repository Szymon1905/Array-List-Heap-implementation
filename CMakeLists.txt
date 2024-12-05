cmake_minimum_required(VERSION 3.24)
project(Projekt_SDIZO_nr_1_Szymon_Borzdynski)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(Projekt_SDIZO_nr_1_Szymon_Borzdynski main.cpp Czasomierz.cpp Czasomierz.h Opcje.cpp Opcje.h Tablica.cpp Tablica.h Lista.cpp Lista.h Testy.cpp Testy.h Kopiec.cpp Kopiec.h)
