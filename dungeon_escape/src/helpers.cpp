#include "helpers.hpp"
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
#include <termios.h>
#include <unistd.h>

static struct termios new_io;
static struct termios old_io;

static int cbreak(int fd)
{
    if ((tcgetattr(fd, &old_io)) == -1)
        return -1;
    new_io = old_io;
    new_io.c_lflag = new_io.c_lflag & ~(ECHO | ICANON);
    new_io.c_cc[VMIN] = 1;
    new_io.c_cc[VTIME] = 0;

    if ((tcsetattr(fd, TCSAFLUSH, &new_io)) == -1)
        return -1;
    return 1;
}

int getch(void)
{
    int c;

    if (cbreak(STDIN_FILENO) == -1)
    {
        printf("Fehler bei der Funktion cbreak ... \n");
        exit(EXIT_FAILURE);
    }
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_io);
    return c;
}

void clearScreen()
{
    system("clear");
}

#elif __WIN32__ || _MSC_VER || __MS_DOS__
#include <conio.h>

void clearScreen()
{
    system("cls");
}

int getch(void)
{
    _getch();
}
#endif
