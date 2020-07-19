#include <catch2/catch.hpp>
#include "shared_pointer.hpp"
#include "alive.hpp"

TEST_CASE("shared pointer compare empty", "[shared_pointer]")
{
    SharedPointer<int> lhs;
    SharedPointer<int> rhs;

    REQUIRE(lhs == rhs);
    REQUIRE(!(lhs != rhs));

    REQUIRE(!(lhs < rhs));
    REQUIRE(!(lhs > rhs));
    REQUIRE(lhs <= rhs);
    REQUIRE(lhs >= rhs);
}

TEST_CASE("shared pointer compare first empty", "[shared_pointer]")
{
    SharedPointer<int> lhs;
    SharedPointer<int> rhs(new int(10));

    REQUIRE(!(lhs == rhs));
    REQUIRE(lhs != rhs);

    REQUIRE(lhs < rhs);
    REQUIRE(!(lhs > rhs));
    REQUIRE(lhs <= rhs);
    REQUIRE(!(lhs >= rhs));
}

TEST_CASE("shared pointer compare second empty", "[shared_pointer]")
{
    SharedPointer<int> lhs(new int(10));
    SharedPointer<int> rhs;

    REQUIRE(!(lhs == rhs));
    REQUIRE(lhs != rhs);

    REQUIRE(!(lhs < rhs));
    REQUIRE(lhs > rhs);
    REQUIRE(!(lhs <= rhs));
    REQUIRE(lhs >= rhs);
}

TEST_CASE("shared pointer compare both valid", "[shared_pointer]")
{
    SharedPointer<int> lhs(new int(10));
    SharedPointer<int> rhs(new int(6));

    REQUIRE(!(lhs == rhs));
    REQUIRE(lhs != rhs);

    bool leftSmaller = lhs.get() < rhs.get();

    REQUIRE(leftSmaller == (lhs < rhs));
    REQUIRE(leftSmaller != (lhs > rhs));
    REQUIRE(leftSmaller == (lhs <= rhs));
    REQUIRE(leftSmaller != (lhs >= rhs));
}