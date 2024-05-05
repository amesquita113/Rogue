#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


// color pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2

typedef struct
{
    int y;
    int x;
} Position;

// Tile struct -- Wall and other map items
typedef struct
{
    char ch;            // character for tile
    int color;          // color of tile
    int item_id;        // ID number of item, if any in the space
    bool walkable;      // is tile walkable
    bool transparent;   // if tile is transparent/not displayed
    bool visible;       // if tile is in the field of view
    bool seen;          // if tile has been seen already by the player    
} Tile;

// Room struct -- Used in auto generating maps
typedef struct
{
    int height;
    int width;
    Position pos;
    Position center;
} Room;


// Entity struct -- Used for storing player and monster data
typedef struct
{
    Position pos;
    char ch;
    char name[10];
    int color;
    int health_max;
    int health;
    int magic_max;
    int magic;
    int xp;
    int level;
} Entity;

//  Item struct -- Used for storing information about items in game
typedef struct
{
    Position pos;
    char ch;
    int color;
    char name[15];
    int item_type;
    int item_value;
} Item;


// draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

// engine.c functions
bool cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c functions
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// player.c functions
Entity* createPlayer(Position start_pos, char player_name[10]);
void handleInput(int input);
void movePlayer(Position newPos);

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// fov.c functions
void makeFOV(Entity* player);
void clearFOV(Entity* player);
int getDistance(Position origin, Position target);
bool isInMap(int y, int x);
bool lineOfSight(Position origin, Position target);
int getSign(int a);

// messages.c functioins
void statusMessage(char *message);
void drawPlayerHUD(void);

// externs
extern const int WINDOW_X;
extern const int WINDOW_Y;
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern const int DRAW_WINDOW_HEIGHT;
extern const int DRAW_WINDOW_WIDTH;
extern Entity* player;
extern Tile** map;
extern char message[79];

#endif