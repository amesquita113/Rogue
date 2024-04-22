/* 
    main.c -- main file for roguelike programmed in C 
*/

#include "../include/rogue.h"
#include <ncurses.h>

Entity* player;


int main(void)
{
    cursesSetup();

    Position start_pos = { 10, 20 };
    player = createPlayer(start_pos);

    gameLoop();

    closeGame();
    
    return 0;
}

