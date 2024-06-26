/*
    engine.c -- main display engine.  Initializes curses, checks for color terminal then handles
                main game loop.
*/

#include "../include/rogue.h"

bool cursesSetup(void)
{
    //resizeterm(39, 100);
    initscr();
    noecho();
    curs_set(0);

    if (has_colors())
    {
        start_color();

        init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
        init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);

        return true;
    }
    else
    {
        mvprintw(20, 50, "Your terminal doesn't support color.  Can't start game!");
        getch();
        return false;
    }
}

void gameLoop(void)
{
    int ch;

    makeFOV(player);
    drawEverything();

    
    while(ch = getch())
    {
        if (ch == 'q')
        {
            break;
        }
    

        handleInput(ch);
        drawEverything();        
    }
}

void closeGame(void)
{
    endwin();
    free(player);
}