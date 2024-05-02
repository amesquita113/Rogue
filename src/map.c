/*
    map.c -- map building code
*/

#include "../include/rogue.h"

// function to create a full map of wall tiles "#"
Tile** createMapTiles(void)
{
    Tile** tiles = calloc(MAP_HEIGHT, sizeof(Tile*));

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiles[y][x].ch = '#';
            tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
            tiles[y][x].walkable = false;
            tiles[y][x].transparent = false;
            tiles[y][x].visible = false;
            tiles[y][x].seen = false;
        }
    }

    return tiles;
}

// creates rooms for map based on n_rooms variable and calls the function to connect the rooms
Position setupMap(void)
{
    int y, x, height, width, n_rooms;
    n_rooms = (rand() % 11) + 6;
    Room* rooms = calloc(n_rooms, sizeof(Room));
    Position start_pos;

    for (int i = 0; i < n_rooms; i++)
    {
        y = (rand() % (MAP_HEIGHT - 10)) + 2;
        x = (rand() % (MAP_WIDTH - 20)) + 2;
        height = (rand() % 7) + 3;
        width = (rand() % 15) + 5;
        rooms[i] = createRoom(y, x, height, width);
        addRoomToMap(rooms[i]);

        if (i > 0)
        {
            connectRoomCenters(rooms[i-i].center, rooms[i].center);
        }
    }

    start_pos.y = rooms[1].center.y;
    start_pos.x = rooms[1].center.x;

    free(rooms);

    return start_pos;
}

void freeMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }    
    free(map);
}