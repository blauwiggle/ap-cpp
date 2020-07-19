#include <catch2/catch.hpp>
#include <memory>
#include "shared_pointer.hpp"
#include "alive.hpp"

TEST_CASE("shared pointer copy assign to empty", "[shared_pointer]")
{
    bool objectAlive;
    {
        Alive *object = new Alive(4, objectAlive);
        SharedPointer<Alive> source(object);
        {
            SharedPointer<Alive> target;

            target = source;

            REQUIRE(source.get() == object);
            REQUIRE(target.get() == object);
            REQUIRE(objectAlive);
        }
        REQUIRE(objectAlive);
    }
    REQUIRE(!objectAlive);
}

TEST_CASE("shared pointer copy assign to valid", "[shared_pointer]")
{
    bool sourceAlive;
    bool targetAlive;
    {
        auto object = new Alive(3, sourceAlive);
        SharedPointer<Alive> source(object);
        {
            SharedPointer<Alive> target(new Alive(6, targetAlive));

            target = source;

            REQUIRE(source.get() == object);
            REQUIRE(target.get() == object);
            REQUIRE(!targetAlive);
            REQUIRE(sourceAlive);
        }
        REQUIRE(sourceAlive);
    }
    REQUIRE(!sourceAlive);
}

TEST_CASE("shared pointer copy assign inverse destruction order", "[shared_pointer]")
{
    bool objectAlive;
    {
        Alive *object = new Alive(4, objectAlive);
        // dynamically allocate here to be able to delete it explicitly
        SharedPointer<Alive> *source = new SharedPointer<Alive>(object);

        SharedPointer<Alive> target;

        target = *source;

        delete source;

        REQUIRE(target.get() == object);
        REQUIRE(objectAlive);
    }

    REQUIRE(!objectAlive);
}
