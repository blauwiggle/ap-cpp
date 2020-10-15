set(SOURCES

)

set(TESTS

)

add_executable(demos
    src/main.cpp
    ${SOURCES}
)
target_include_directories(demos PRIVATE include)


add_executable(demos_tests
    test/tests.cpp
    ${SOURCES}
    ${TESTS}
)
target_link_libraries(demos_tests Catch2::Catch2)
target_include_directories(demos_tests PRIVATE include)
catch_discover_tests(demos_tests)