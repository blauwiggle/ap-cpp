set(SOURCES
)

set(TESTS
    test/unique_create.cpp
    test/unique_move_construct.cpp
    test/unique_move_assign.cpp
    test/unique_comparison.cpp
    test/shared_create.cpp
    test/shared_copy_construct.cpp
    test/shared_copy_assign.cpp
    test/shared_move_construct.cpp
    test/shared_move_assign.cpp
    test/shared_comparison.cpp
)

add_executable(smart_pointer
    src/main.cpp
    ${SOURCES}
)
target_include_directories(smart_pointer PRIVATE include)


add_executable(smart_pointer_tests
    test/tests.cpp
    ${SOURCES}
    ${TESTS}
)
target_link_libraries(smart_pointer_tests Catch2::Catch2)
target_include_directories(smart_pointer_tests PRIVATE include)
catch_discover_tests(smart_pointer_tests)