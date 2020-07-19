#include <catch2/catch.hpp>
#include "shared_pointer.hpp"
#include "alive.hpp"

TEST_CASE("shared pointer create empty", "[shared_pointer]")
{
    SharedPointer<int> ptr;

    REQUIRE(ptr.get() == nullptr);
    REQUIRE(static_cast<bool>(ptr) == false);
}

TEST_CASE("shared pointer create with object", "[shared_pointer]")
{
    auto obj = new int(5);
    SharedPointer<int> ptr(obj);

    REQUIRE(ptr.get() == obj);
    REQUIRE(static_cast<bool>(ptr) == true);
    REQUIRE(*ptr == 5);
}

TEST_CASE("shared pointer destroy when out of scope", "[shared_pointer]")
{

    bool isAlive = false;
    {
        auto obj = new Alive(4, isAlive);
        SharedPointer<Alive> ptr(obj);
        REQUIRE(isAlive);
        REQUIRE(ptr->value == 4);
    }

    REQUIRE(!isAlive);
}