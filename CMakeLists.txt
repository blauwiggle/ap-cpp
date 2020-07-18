cmake_minimum_required(VERSION 3.5)

project(ap-cpp LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/third_party/lib/Catch2/contrib")
include(CTest)
include(Catch)

add_subdirectory(third_party/lib/Catch2)

add_subdirectory(todo_list)
add_subdirectory(dungeon_escape)
add_subdirectory(int_array)
add_subdirectory(smart_pointer)

