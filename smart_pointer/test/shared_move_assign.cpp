#include <catch2/catch.hpp>
#include <memory>
#include "shared_pointer.hpp"
#include "alive.hpp"

TEST_CASE("shared pointer move assign to empty", "[shared_pointer]")
{
    bool objectAlive;
    Alive *object = new Alive(4, objectAlive);
    SharedPointer<Alive> source(object);

    SharedPointer<Alive> target;

    target = std::move(source);

    REQUIRE(source.get() == nullptr);
    REQUIRE(target.get() == object);
    REQUIRE(objectAlive);
}

TEST_CASE("shared pointer move assign to valid", "[shared_pointer]")
{
    bool sourceAlive;
    bool targetAlive;
    auto object = new Alive(3, sourceAlive);
    SharedPointer<Alive> source(object);

    SharedPointer<Alive> target(new Alive(6, targetAlive));

    target = std::move(source);

    REQUIRE(source.get() == nullptr);
    REQUIRE(target.get() == object);
    REQUIRE(!targetAlive);
    REQUIRE(sourceAlive);
}
