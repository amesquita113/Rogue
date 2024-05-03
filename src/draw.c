/*
    draw.c -- code to draw the map and player every turn
*/

#include "../include/rogue.h"

void drawMap(void)
{
    int x, y;
    int map_x, map_y;  
    
    if (player->pos.y < DRAW_WINDOW_HEIGHT) {
        int y = 2;
        int map_y = 1;
    }
    else {
        int y = DRAW_WINDOW_HEIGHT + 2;
        int map_y = DRAW_WINDOW_HEIGHT + 1;
    }

    if (player->pos.x < DRAW_WINDOW_WIDTH) {
        int x = 15;
        int map_x = 1;
    }
    else {   
        int x = DRAW_WINDOW_WIDTH + 15;
        int map_x = DRAW_WINDOW_WIDTH + 1;
    }

    
    for (int iy = 0; iy < DRAW_WINDOW_HEIGHT; iy++)
    {
        y++;
        map_y++;

        for (int ix = 0; ix < DRAW_WINDOW_WIDTH; ix++)
        {
            x++;
            map_x++;

            if (map[map_y][map_x].visible)
            {
                mvaddch( y, x, map[map_y][map_x].ch | map[map_y][map_x].color);
            }
            else if (map[map_y][map_x].seen)
            {
                mvaddch( y, x, map[map_y][map_x].ch | COLOR_PAIR(SEEN_COLOR));
            }
            else{
                mvaddch( map_y, map_x, ' ');
            }
        }
    }
}

void drawEntity(Entity* entity)
{
    int x, y;
    int map_x, map_y;  
    
    if (entity->pos.y < (MAP_HEIGHT / 2)) 
    {
        int y = entity->pos.y + 2;
        // int map_y = 1;
    }
    else 
    {
        int y = entity->pos.y + DRAW_WINDOW_HEIGHT + 2;
        // int map_y = DRAW_WINDOW_HEIGHT + 1;
    }

    if (entity->pos.x < (MAP_WIDTH / 2))
    {
        int x = entity->pos.x + 15;
        // int map_x = 1;
    }
    else
    {   
        int x = entity->pos.x + DRAW_WINDOW_WIDTH + 15;
        // int map_x = DRAW_WINDOW_WIDTH + 1;
    }

    mvaddch( y, x, entity->ch | entity->color);
    //mvaddch(entity->pos.y, entity->pos.x, entity->ch | entity->color);
}

void drawEverything(void)
{
    clear();
    drawMap();
    drawEntity(player);
    drawPlayerHUD();

    // Clear status message after each turn
    statusMessage("");
}