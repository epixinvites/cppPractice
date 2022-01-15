project(OpenGL_Subproject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(chapter6_main main.cc mesh.cc camera.cc shaderLoader.cc light_renderer.cc)

target_link_libraries(chapter6_main -lglfw -lGLEW -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl)