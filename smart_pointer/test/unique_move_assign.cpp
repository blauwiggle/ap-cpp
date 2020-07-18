#include <catch2/catch.hpp>
#include <memory>
#include "unique_pointer.hpp"
#include "alive.hpp"

TEST_CASE("move assign to empty", "[unique_pointer]")
{
    bool objectAlive;
    Alive *object = new Alive(4, objectAlive);
    UniquePointer<Alive> source(object);

    UniquePointer<Alive> target;

    target = std::move(source);

    REQUIRE(source.get() == nullptr);
    REQUIRE(target.get() == object);
    REQUIRE(objectAlive);
}

TEST_CASE("move assign to valid", "[unique_pointer]")
{
    bool sourceAlive;
    bool targetAlive;
    auto object = new Alive(3, sourceAlive);
    UniquePointer<Alive> source(object);

    UniquePointer<Alive> target(new Alive(6, targetAlive));

    target = std::move(source);

    REQUIRE(source.get() == nullptr);
    REQUIRE(target.get() == object);
    REQUIRE(!targetAlive);
    REQUIRE(sourceAlive);
}
