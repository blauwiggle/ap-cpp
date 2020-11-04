#include "helpers.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    //std::cout << "Try to escape the dungeon, use 'W' (up), 'A' (left), 'S' (down), and 'D' (right) to move around.";

    char input; //= getCharacter();

    bool won = false;

    do
    {
        printf(
            "Try to escape the dungeon. Use %s, %s, %s, %s to move around.\nUse %s.",
            "'W' (up)",
            "'A' (left)",
            "'S' (down)",
            "'D' (right)",
            "'q' (exit)");

        int playerCommand = getCharacter();
        printInput(playerCommand);

        //system("clear");

        if (playerCommand == 'q')
        {
            break;
        }

    } while (!won);

    return 0;
}