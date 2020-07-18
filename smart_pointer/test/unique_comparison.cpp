#include <catch2/catch.hpp>
#include "unique_pointer.hpp"
#include "alive.hpp"

TEST_CASE("compare empty", "[unique_pointer]")
{
    UniquePointer<int> lhs;
    UniquePointer<int> rhs;

    REQUIRE(lhs == rhs);
    REQUIRE(!(lhs != rhs));

    REQUIRE(!(lhs < rhs));
    REQUIRE(!(lhs > rhs));
    REQUIRE(lhs <= rhs);
    REQUIRE(lhs >= rhs);
}

TEST_CASE("compare first empty", "[unique_pointer]")
{
    UniquePointer<int> lhs;
    UniquePointer<int> rhs(new int(10));

    REQUIRE(!(lhs == rhs));
    REQUIRE(lhs != rhs);

    REQUIRE(lhs < rhs);
    REQUIRE(!(lhs > rhs));
    REQUIRE(lhs <= rhs);
    REQUIRE(!(lhs >= rhs));
}

TEST_CASE("compare second empty", "[unique_pointer]")
{
    UniquePointer<int> lhs(new int(10));
    UniquePointer<int> rhs;

    REQUIRE(!(lhs == rhs));
    REQUIRE(lhs != rhs);

    REQUIRE(!(lhs < rhs));
    REQUIRE(lhs > rhs);
    REQUIRE(!(lhs <= rhs));
    REQUIRE(lhs >= rhs);
}

TEST_CASE("compare both valid", "[unique_pointer]")
{
    UniquePointer<int> lhs(new int(10));
    UniquePointer<int> rhs(new int(6));

    REQUIRE(!(lhs == rhs));
    REQUIRE(lhs != rhs);

    bool leftSmaller = lhs.get() < rhs.get();

    REQUIRE(leftSmaller == (lhs < rhs));
    REQUIRE(leftSmaller != (lhs > rhs));
    REQUIRE(leftSmaller == (lhs <= rhs));
    REQUIRE(leftSmaller != (lhs >= rhs));
}