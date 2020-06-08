set(SOURCES
    src/int_array.cpp
)

set(TESTS
    test/create.cpp
    test/append.cpp
    test/erase.cpp
    test/copy_construct.cpp
    test/copy_assign.cpp
    test/move_construct.cpp
    test/move_assign.cpp
)

add_executable(int_array
    src/main.cpp
    ${SOURCES}
)
target_include_directories(int_array PRIVATE include)


add_executable(int_array_tests
    test/tests.cpp
    ${SOURCES}
    ${TESTS}
)
target_link_libraries(int_array_tests Catch2::Catch2)
target_include_directories(int_array_tests PRIVATE include)
catch_discover_tests(int_array_tests)