cmake_minimum_required(VERSION 3.10)
project(C++_Game_Development_by_Example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Wredundant-decls -Wundef -Wno-unused")

link_directories(libs/)
include_directories(include/)

add_subdirectory(Chapter_3_SFML_Subproject)
add_subdirectory(Chapter_4_SFML_Game_Creation)
add_subdirectory(Chapter_5_SFML_Game_Finalizing)
add_subdirectory(Chapter_6_Getting_Started_With_OpenGL)
