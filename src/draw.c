/*
    draw.c -- code to draw the map and player every turn
*/

#include "../include/rogue.h"


//*
void drawMap(void)
{
    //int x = 15;
    //int y = 2;
    int map_x = 0;
    int map_y = 0;  
    
    if (player->pos.y < DRAW_WINDOW_HEIGHT) {
        map_y = 0;
    }
    else {
        //y = DRAW_WINDOW_HEIGHT + 1;
        map_y = DRAW_WINDOW_HEIGHT;
    }

    if (player->pos.x < DRAW_WINDOW_WIDTH) {
        //x = 14;
        map_x = 0;
    }
    else {   
        //x = DRAW_WINDOW_WIDTH + 14;
        map_x = DRAW_WINDOW_WIDTH;
    }

    mvprintw( 4, 1, "map y: %d x: %d", map_y, map_x);   // for testing


    for (int y = 0; y < DRAW_WINDOW_HEIGHT; y++)
    {
        for (int x = 0; x < DRAW_WINDOW_WIDTH; x++)
        {
            if (map[map_y][map_x].visible)
            {
                mvaddch( y + WINDOW_Y, x + WINDOW_X, map[map_y][map_x].ch | map[map_y][map_x].color);
            }
            else if (map[map_y][map_x].seen)
            {
                mvaddch( y + WINDOW_Y, x + WINDOW_X, map[map_y][map_x].ch | COLOR_PAIR(SEEN_COLOR));
            }
            else{
                mvaddch( y + WINDOW_Y, x + WINDOW_X, map[map_y][map_x].ch | COLOR_PAIR(SEEN_COLOR));

                //mvaddch( map_y, map_x, ' '); 
            }

            map_x++;
        }


        map_x += DRAW_WINDOW_WIDTH + 1;
        map_y++;
    }
}
//*/

/*
void drawMap(void)
{ 
  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    for (int x = 0; x < MAP_WIDTH; x++)
    { 
      mvaddch( y, x, map[y][x].ch | map[y][x].color);
    } 
  } 
} 
*/

void drawEntity(Entity* entity)
{
    int x, y;
    //int map_x, map_y;  
    
    if (entity->pos.y < DRAW_WINDOW_HEIGHT) 
    {
        y = entity->pos.y + WINDOW_Y;
        // int map_y = 1;
    }
    else 
    {
        y = entity->pos.y - DRAW_WINDOW_HEIGHT + WINDOW_Y;
        // int map_y = DRAW_WINDOW_HEIGHT + 1;
    }

    if (entity->pos.x < DRAW_WINDOW_WIDTH)
    {
        x = entity->pos.x + WINDOW_X;
        // int map_x = 1;
    }
    else
    {   
        x = entity->pos.x - DRAW_WINDOW_WIDTH + WINDOW_X;
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