#include <catch2/catch.hpp>
#include <memory>
#include "int_array.hpp"

TEST_CASE("move construct", "[int_array]")
{
    IntArray sourceArray(10);
    const auto &sourceRef(sourceArray);
    auto *sourceFirst = &sourceRef[0];

    IntArray targetArray(std::move(sourceArray));
    const auto &targetRef(targetArray);
    auto *targetFirst = &targetRef[0];

    REQUIRE(sourceArray.size() == 0);
    REQUIRE(targetArray.size() == 10);
    REQUIRE(sourceFirst == targetFirst);
}
