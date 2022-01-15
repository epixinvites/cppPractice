project(SFML_Subproject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(drawing_shapes drawing_shapes.cc)
add_executable(drawing_sprites drawing_sprites.cc)

target_link_libraries(drawing_shapes -Wl,--copy-dt-needed-entries -lsfml-graphics)
target_link_libraries(drawing_sprites -Wl,--copy-dt-needed-entries -lsfml-graphics)