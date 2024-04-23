/* 
    main.c -- main file for roguelike programmed in C 
*/

#include "../include/rogue.h"
#include <ncurses.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity* player;
Tile** map;         // pointer to pointers in the Tile struct


int main(void)
{
    cursesSetup();

    Position start_pos = { 10, 20 };
    player = createPlayer(start_pos);
    map = createMapTiles();

    gameLoop();

    closeGame();
    
    return 0;
}

