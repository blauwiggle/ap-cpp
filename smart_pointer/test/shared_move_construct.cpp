#include <catch2/catch.hpp>
#include <memory>
#include "shared_pointer.hpp"
#include "alive.hpp"

TEST_CASE("shared pointer move construct", "[shared_pointer]")
{
    bool objectAlive;
    Alive *object = new Alive(4, objectAlive);
    SharedPointer<Alive> source(object);

    SharedPointer<Alive> target(std::move(source));

    REQUIRE(source.get() == nullptr);
    REQUIRE(target.get() == object);
    REQUIRE(objectAlive);
}
