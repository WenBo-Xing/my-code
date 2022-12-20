#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30
#define WINDOW_START_Y ((LINES / 2) - WINDOW_HEIGHT / 2)
#define WINDOW_START_X ((COLS / 2) - WINDOW_WIDTH / 2)
#define SUB_WINDOW_WIDTH (WINDOW_WIDTH - 2)
#define SUB_WINDOW_HEIGHT (WINDOW_HEIGHT - 2)
#define SUB_WINDOW_START_Y ((LINES / 2) - SUB_WINDOW_HEIGHT / 2)
#define SUB_WINDOW_START_X ((COLS / 2) - SUB_WINDOW_WIDTH / 2)
#define WINDOW_END_Y (WINDOW_START_Y + WINDOW_HEIGHT)
#define WINDOW_END_X (WINDOW_START_X + WINDOW_WIDTH)

#define SNAKE_MARK '#'
#define FOOD_MARK '@'
#define INIT_SNAKE_SIZE 4
#define MAP_SIZE ((WINDOW_HEIGHT - 2) * (WINDOW_WIDTH - 2))

//snake direction enum
typedef enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
} direction;

//map tile enum
typedef enum tile {
    EMPTY,
    WALL,
    SNAKE_HEAD,
    SNAKE_BODY,
    SNAKE_TAIL,
    FOOD
} tile;

//double linked list to store snake
typedef struct list {
    int x;
    int y;
    struct list* previous;
    struct list* next;
} list, *plist;

extern tile map[WINDOW_HEIGHT][WINDOW_WIDTH];
extern plist snake_head;
extern plist snake_tail;
extern int snake_size;
extern plist food;
extern direction snake_direction;
extern bool is_win;
extern bool is_over;
extern int snake_level;
extern int* level_info;
extern int level_size;
extern int interval;


void init_snake();
void init_map();
void init_food();
void create_food();
void init_game();
void print_map(WINDOW* window);
void eat_food();
bool can_snake_move();
void move_snake();
void update_snake_head();
void update_snake_tail();
void get_next_loc(int* y, int* x);
void run();
void handle_key_input(int key);
bool player_snake_play(WINDOW* window);
bool can_snake_move_up();
bool can_snake_move_down();
bool can_snake_move_left();
bool can_snake_move_right();
void free_all();
void change_level();

#endif //SNAKEGAME_SNAKE_H
