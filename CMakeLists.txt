cmake_minimum_required(VERSION 3.27)
project(LR8)

add_subdirectory(Sources)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC StaticLibLR8)
