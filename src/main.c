/* 
    main.c -- main file for roguelike programmed in C 
*/

#include "../include/rogue.h"


int main(void)
{
    initscr();
    noecho();
    curs_set(0);


    while (getch() != 'q') 
    {
        mvaddch(10, 20, '@');
    }

    endwin();

    return 0;
}

