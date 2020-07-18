#include <catch2/catch.hpp>
#include "unique_pointer.hpp"
#include "alive.hpp"

TEST_CASE("create empty", "[unique_pointer]")
{
    UniquePointer<int> ptr;

    REQUIRE(ptr.get() == nullptr);
    REQUIRE(static_cast<bool>(ptr) == false);
}

TEST_CASE("create with object", "[unique_pointer]")
{
    auto obj = new int(5);
    UniquePointer<int> ptr(obj);

    REQUIRE(ptr.get() == obj);
    REQUIRE(static_cast<bool>(ptr) == true);
    REQUIRE(*ptr == 5);
}

TEST_CASE("destroy when out of scope", "[unique_pointer]")
{

    bool isAlive = false;
    {
        auto obj = new Alive(4, isAlive);
        UniquePointer<Alive> ptr(obj);
        REQUIRE(isAlive);
        REQUIRE(ptr->value == 4);
    }

    REQUIRE(!isAlive);
}