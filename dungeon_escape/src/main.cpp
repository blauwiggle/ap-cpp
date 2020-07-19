#include "helpers.hpp"
#include "dungeon.hpp"

int main(int argc, char *argv[])
{
    Dungeon dungeon;

    std::cout << "You are trapped in a maze, try to escape!\r\n";
    std::cout << "User 'w', 'a', 's' and 'd' to move.\r\n";
    dungeon.printVisibleAreaTo(std::cout);
    getCharacter(); //std::cin.get();

    bool won = false;
    do
    {
        clearScreen(); // std::cout << std::endl;

        dungeon.printVisibleAreaTo(std::cout);
        char input = getCharacter(); //std::cin.get();

        switch (input)
        {
        case 'W':
        case 'w':
            won = dungeon.moveUp();
            break;
        case 'A':
        case 'a':
            won = dungeon.moveLeft();
            break;
        case 's':
        case 'S':
            won = dungeon.moveDown();
            break;
        case 'D':
        case 'd':
            won = dungeon.moveRight();
            break;
        }
    } while (!won);

    clearScreen(); // std::cout << std::endl;
    dungeon.printVisibleAreaTo(std::cout);

    std::cout << "congratulations you escaped the maze!";
    getCharacter(); //std::cin.get();

    return 0;
}