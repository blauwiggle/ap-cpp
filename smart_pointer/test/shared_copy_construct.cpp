#include <catch2/catch.hpp>
#include <memory>
#include "shared_pointer.hpp"
#include "alive.hpp"

TEST_CASE("shared pointer copy construct", "[shared_pointer]")
{
    bool objectAlive;
    {
        Alive *object = new Alive(4, objectAlive);
        SharedPointer<Alive> source(object);
        {
            SharedPointer<Alive> target(source);

            REQUIRE(source.get() == object);
            REQUIRE(target.get() == object);
            REQUIRE(objectAlive);
        }

        REQUIRE(source.get() == object);

        REQUIRE(objectAlive);
    }
    REQUIRE(!objectAlive);
}

TEST_CASE("shared pointer copy construct inverse destruction order", "[shared_pointer]")
{
    bool objectAlive;
    {
        Alive *object = new Alive(4, objectAlive);
        // dynamically allocate here to be able to delete it explicitly
        SharedPointer<Alive> *source = new SharedPointer<Alive>(object);

        SharedPointer<Alive> target(*source);

        delete source;

        REQUIRE(target.get() == object);
        REQUIRE(objectAlive);
    }

    REQUIRE(!objectAlive);
}
