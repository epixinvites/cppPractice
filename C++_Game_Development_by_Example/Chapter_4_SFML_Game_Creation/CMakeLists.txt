project(SFML_Subproject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(main main.cc hero.cc)

target_link_libraries(main -Wl,--copy-dt-needed-entries -lsfml-graphics)