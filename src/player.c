#include "../include/rogue.h"


Entity* createPlayer(Position start_pos)
{
    Entity* newPlayer = calloc(1, sizeof(Entity));

    newPlayer->pos.y = start_pos.y;
    newPlayer->pos.x = start_pos.x;
    newPlayer->ch = '@';

    return newPlayer;
}

void handleInput(int input)
{
    switch(input)
    {
        // move up on 'k'
        case 'k':
            player->pos.y--;
            break;
        // move down on 'j'
        case 'j':
            player->pos.y++;
            break;
        // move left on 'h'
        case 'h':
            player->pos.x--;
            break;
        // move right on 'l'
        case 'l':
            player->pos.x++;
            break;
        // any unhandled input
        default:
            break;
    }
}