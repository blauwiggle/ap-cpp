#include <catch2/catch.hpp>
#include "int_array.hpp"

TEST_CASE("copy assign", "[int_array]")
{

    IntArray sourceArray(10);
    const auto &sourceRef(sourceArray);
    auto *sourceFirst = &sourceRef[0];

    for (int i = 0; i < 10; ++i)
    {
        sourceArray[i] = i;
    }

    IntArray targetArray;
    targetArray = sourceArray;
    const auto &targetRef(targetArray);
    auto *targetFirst = &targetRef[0];

    REQUIRE(sourceArray.size() == 10);
    REQUIRE(targetArray.size() == 10);
    REQUIRE(sourceFirst != targetFirst);

    for (int i = 0; i < 10; ++i)
    {
        REQUIRE(sourceArray[i] == i);
        REQUIRE(targetArray[i] == i);
    }
}
