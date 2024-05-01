/*
    messages.c -- functions to display game data/player info on screen
*/

#include "../include/rogue.h"


void statusMessage(char *message)
{
    mvaddstr( 1, 1, message);

}