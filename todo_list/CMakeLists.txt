set(SOURCES
    src/todo_list.cpp)

set(TESTS
    test/test.cpp)

add_executable(todo_list
    src/main.cpp
    ${SOURCES})
target_include_directories(todo_list PRIVATE include)

add_executable(todo_list_tests
    test/tests.cpp
    ${SOURCES}
    ${TESTS})
target_link_libraries(todo_list_tests Catch2::Catch2)
target_include_directories(todo_list_tests PRIVATE include)
catch_discover_tests(todo_list_tests)