cmake_minimum_required(VERSION 3.21)
project(a3_4_914_Claudia_Moisiuc C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
set(CMAKE_C_STANDARD 11)


add_executable(a3_4_914_Claudia_Moisiuc
        "src/source files/ui.c" "src/Header files/medicine.h" "src/source files/service.c" "src/source files/main.c" "src/source files/medicine.c" "src/Header files/dinamic vector.h" "src/source files/dinamic vector.c" "src/Header files/repository.h" "src/Header files/service.h" "src/Header files/ui.h" "src/source files/repository.c" "src/Header files/operation.h" "src/source files/operation.c" "src/Header files/undo_redo.h" "src/source files/undo_redo.c" "src/source files/tests.c")
