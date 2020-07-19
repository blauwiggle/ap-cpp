#include "dungeon.hpp"
#include <algorithm>

Dungeon::Dungeon()
    : position({1, 1}), map({{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                             {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1, 0, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 0, 0, 1, 1, 1},
                             {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                             {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
                             {1, 0, 0, 0, 0, 0, 0, 1, 0, 2},
                             {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}})
{
}

Dungeon::~Dungeon()
{
}

void Dungeon::printVisibleAreaTo(std::ostream &stream)
{
    for (int y = std::max(position.y - 2, 0); y <= std::min(position.y + 2, (int)map.size() - 1); ++y)
    {
        for (int x = std::max(position.x - 2, 0); x <= std::min(position.x + 2, (int)map[y].size() - 1); ++x)
        {
            printSinglePositionTo(stream, {x, y});
        }
        stream << "\r\n";
    }
}

void Dungeon::printSinglePositionTo(std::ostream &stream, Vector2D position)
{
    char characterToPrint;

    if (position.x == this->position.x && position.y == this->position.y)
    {
        characterToPrint = 'X';
    }
    else
    {
        switch (map[position.y][position.x])
        {
        case 0:
            characterToPrint = '_';
            break;
        case 1:
            characterToPrint = 'O';
            break;
        case 2:
            characterToPrint = 'T';
            break;
        }
    }

    stream << characterToPrint;
}

bool Dungeon::moveLeft()
{
    Vector2D newPosition = {std::max(0, position.x - 1), position.y};
    return moveTo(newPosition);
}

bool Dungeon::moveRight()
{
    Vector2D newPosition = {std::min((int)map[position.y].size() - 1, position.x + 1), position.y};
    return moveTo(newPosition);
}

bool Dungeon::moveUp()
{
    Vector2D newPosition = {position.x, std::max(0, position.y - 1)};
    return moveTo(newPosition);
}

bool Dungeon::moveDown()
{
    Vector2D newPosition = {position.x, std::min((int)map.size() - 1, position.y + 1)};
    return moveTo(newPosition);
}

bool Dungeon::moveTo(Vector2D newPosition)
{
    if (hitsWall(newPosition))
    {
        return false;
    }

    position = newPosition;

    return isGoal(newPosition);
}

bool Dungeon::hitsWall(Vector2D position)
{
    return map[position.y][position.x] == 1;
}

bool Dungeon::isGoal(Vector2D position)
{
    return map[position.y][position.x] == 2;
}