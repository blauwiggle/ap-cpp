#pragma once
#include "vector2d.hpp"
#include <string>
#include <vector>

class Dungeon
{
private:
    Vector2D playerPosition;
    std::vector<std::string> currentLevel;

public:
    Dungeon();
};
