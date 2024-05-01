/*
    player.c -- Create new entity for the player, also handles player input 
*/

#include "../include/rogue.h"


Entity* createPlayer(Position start_pos, char player_name[10])
{
    Entity* newPlayer = calloc(1, sizeof(Entity));

    newPlayer->pos.y = start_pos.y;
    newPlayer->pos.x = start_pos.x;
    newPlayer->ch = '@';
    newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);
    newPlayer->health_max = 15;
    newPlayer->health = newPlayer->health_max;
    newPlayer->magic_max = 10;
    newPlayer->magic = newPlayer->magic_max;
    newPlayer->name = player_name;


    return newPlayer;
}

void handleInput(int input)
{

    Position newPos = { player->pos.y, player->pos.x };

    switch(input)
    {
        // move up on 'k'
        case 'k':
            newPos.y--;
            break;
        // move down on 'j'
        case 'j':
            newPos.y++;
            break;
        // move left on 'h'
        case 'h':
            newPos.x--;
            break;
        // move right on 'l'
        case 'l':
            newPos.x++;
            break;
        // any unhandled input
        default:
            statusMessage("I don't know what that is.");
            break;
    }

    movePlayer(newPos);
}

void movePlayer(Position newPos)
{
    if (map[newPos.y][newPos.x].walkable)
    {
        clearFOV(player);
        player->pos.y = newPos.y;
        player->pos.x = newPos.x;
        makeFOV(player);
    }
    else 
    {
        statusMessage("You walk into a wall!");
    }
}