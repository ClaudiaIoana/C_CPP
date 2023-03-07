cmake_minimum_required(VERSION 3.21)
project(a11_12_914_Claudia_Moisiuc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(scr/header)

add_executable(a11_12_914_Claudia_Moisiuc
        scr/header/duration.h
        scr/header/repository.h
        scr/header/service.h
        scr/source/duration.cpp
        scr/source/repository.cpp
        scr/source/service.cpp scr/source/tutorial.cpp scr/header/tutorial.h scr/source/ui.cpp scr/header/ui.h scr/source/validators.cpp scr/header/validators.h scr/source/main.cpp scr/source/qttest.cpp scr/header/qttest.h scr/qttest.ui)
