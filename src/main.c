/* 
    main.c -- main file for roguelike programmed in C 
*/

#include "../include/rogue.h"
#include <ncurses.h>

const int MAP_HEIGHT = 40;
const int MAP_WIDTH = 64;

Entity* player;
Tile** map;         // pointer to pointers in the Tile struct


int main(void)
{

    char name[10] = "Andre";
    
    Position start_pos;
    bool compatibleTerminal;

    compatibleTerminal = cursesSetup();

    if (compatibleTerminal)
    {
    
        srand(time(NULL));


        map = createMapTiles();
        start_pos = setupMap();
        player = createPlayer(start_pos, name);

        gameLoop();

        closeGame();
    }
    else
    {
        endwin();
    }
    
    return 0;
}

