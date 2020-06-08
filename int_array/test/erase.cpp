#include <catch2/catch.hpp>
#include "int_array.hpp"

TEST_CASE("erase values", "[int_array]")
{
    IntArray array;

    for (int i = 0; i < 10; ++i)
    {
        array.append(i);
    }

    SECTION("erase first element")
    {
        array.erase(0);
        REQUIRE(array.size() == 9);
        for (int i = 0; i < array.size(); ++i)
        {
            REQUIRE(array[i] == i + 1);
        }
    }

    SECTION("erase last element")
    {
        array.erase(9);
        REQUIRE(array.size() == 9);
        for (int i = 0; i < array.size(); ++i)
        {
            REQUIRE(array[i] == i);
        }
    }

    SECTION("erase element in between")
    {
        array.erase(4);
        REQUIRE(array.size() == 9);
        for (int i = 0; i < 4; ++i)
        {
            REQUIRE(array[i] == i);
        }

        for (int i = 4; i < array.size(); ++i)
        {
            REQUIRE(array[i] == i + 1);
        }
    }
}
