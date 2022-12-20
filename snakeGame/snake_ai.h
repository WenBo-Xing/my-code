#ifndef SNAKEGAME_SNAKE_AI_H
#define SNAKEGAME_SNAKE_AI_H

#include "snake.h"

#define SPANNING_TREE_HEIGHT ((WINDOW_HEIGHT-2) / 2)
#define SPANNING_TREE_WIDTH ((WINDOW_WIDTH-2) / 2)

//struct represents nodes in the spanning tree.
typedef struct node {
    bool visited;
    bool can_go_right;
    bool can_go_down;
} node;

//enum node direction represents the direction of the link between the nodes in the spanning tree
typedef enum node_direction {
    NODE_UP,
    NODE_DOWN,
    NODE_LEFT,
    NODE_RIGHT,
} node_direction;

//2D array to store the hamilton cycle order of the map for snake AI play
extern int hamilton_cycle[WINDOW_HEIGHT - 2][WINDOW_WIDTH - 2];
//2D array to store the spanning tree that will create the hamilton cycle array
extern node spanning_tree[SPANNING_TREE_HEIGHT][SPANNING_TREE_WIDTH];
void generate_hamilton_cycle();
void set_visited(int y, int x);
bool is_visited(int y, int x);
void set_can_go_right(int y, int x);
void set_can_go_down(int y, int x);
void generate_spanning_tree();
bool can_go_up(int y, int x);
bool can_go_down(int y, int x);
bool can_go_left(int y, int x);
bool can_go_right(int y, int x);
node_direction find_next_direction(int y, int x, node_direction cur_direction);
bool ai_snake_play(WINDOW *window);
void find_best_direction();
int get_distance(plist node);
int get_distance_by_index(int y, int x);
#endif //SNAKEGAME_SNAKE_AI_H
