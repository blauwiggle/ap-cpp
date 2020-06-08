#include <catch2/catch.hpp>
#include "int_array.hpp"

TEST_CASE("create empty", "[int_array]")
{
    IntArray array;
    const auto &ref(array);

    REQUIRE(array.size() == 0);
    REQUIRE(ref.size() == 0);
}

TEST_CASE("create with size", "[int_array]")
{
    IntArray array(4);
    const auto &ref(array);

    REQUIRE(array.size() == 4);
    REQUIRE(ref.size() == 4);
}