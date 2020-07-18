#include <catch2/catch.hpp>
#include <memory>
#include "unique_pointer.hpp"
#include "alive.hpp"

TEST_CASE("move construct", "[unique_pointer]")
{
    bool objectAlive;
    Alive *object = new Alive(4, objectAlive);
    UniquePointer<Alive> source(object);

    UniquePointer<Alive> target(std::move(source));

    REQUIRE(source.get() == nullptr);
    REQUIRE(target.get() == object);
    REQUIRE(objectAlive);
}
