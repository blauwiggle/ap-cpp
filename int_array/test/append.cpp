#include <catch2/catch.hpp>
#include "int_array.hpp"

TEST_CASE("append values", "[int_array]")
{
    IntArray array;
    for (int i = 0; i < 10; ++i)
    {
        array.append(i + 20);
        REQUIRE(array[i] == i + 20);
        REQUIRE(array.size() == i);
    }
}
