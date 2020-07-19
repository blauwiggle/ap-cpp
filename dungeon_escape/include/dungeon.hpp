#pragma once
#include <vector>
#include <iostream>
#include "vector2d.hpp"

class Dungeon
{
private:
    std::vector<std::vector<char>> map;

    Vector2D position;
    void printSinglePositionTo(std::ostream &stream, Vector2D position);
    bool hitsWall(Vector2D position);
    bool isGoal(Vector2D position);
    bool moveTo(Vector2D position);

public:
    void printVisibleAreaTo(std::ostream &stream);

    bool moveUp();
    bool moveLeft();
    bool moveDown();
    bool moveRight();

    Dungeon();
    ~Dungeon();
};