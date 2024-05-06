/*
    messages.c -- functions to display game data/player info on screen
*/

#include "../include/rogue.h"

// define global variable for our status message 
char message[79];

// function to copy the a string into the message global variable to be used as a status message
void statusMessage(char msg[79])
{
    strncpy(message, msg, 79);
}

// function to draw the HUD for the player
void drawPlayerHUD(void)
{
    mvaddstr( 1, 1, message);
    mvaddstr( 2, 2, player->name);
    mvprintw( 3, 1, "y: %d x: %d", player->pos.y, player->pos.x);   // for testing
}