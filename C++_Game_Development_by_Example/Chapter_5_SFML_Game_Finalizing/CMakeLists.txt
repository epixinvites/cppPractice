project(SFML_Subproject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(chapter5_main main.cc hero.cc enemy.cc rocket.cc base.cc)

target_link_libraries(chapter5_main -Wl,--copy-dt-needed-entries -lsfml-graphics)