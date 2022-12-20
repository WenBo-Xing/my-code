
#include "snake_ai.h"

node spanning_tree[SPANNING_TREE_HEIGHT][SPANNING_TREE_WIDTH];
int hamilton_cycle[WINDOW_HEIGHT - 2][WINDOW_WIDTH - 2];

//links the node[start_y][start_x] to node[y][x] and then do the recursion for the node[y][x] to all other 4 nodes of each direction.
void link_node(int start_y, int start_x, int y, int x) {
    //if the node will be linked is out of the space, then return
    if(y < 0 || x < 0 || y >= SPANNING_TREE_HEIGHT || x >= SPANNING_TREE_WIDTH) {
        return;
    }
    //if already visited this node, then return
    if(is_visited(y, x)) {
        return;
    }
    //sets the new linked node to be visited
    set_visited(y, x);

    //sets the direction of the link between the two nodes, we only keep the direction of UP and DOWN.
    //So if the start node is at the right or down of the next node, we'll instead update the variables for the next node.
    if(start_y < y) {
        set_can_go_down(start_y, start_x);
    } else if (start_y > y) {
        set_can_go_down(y, x);
    } else if (start_x < x) {
        set_can_go_right(start_y, start_x);
    } else {
        set_can_go_right(y, x);
    }

    //shuffle the order of the recursion of the next node.
    int order[4] = {0 ,1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int swap_index = rand() % 4;
        int tmp = order[i];
        order[i] = order[swap_index];
        order[swap_index] = tmp;
    }

    //do recursion for the next node of each direction.
    for(int i = 0; i < 4; i++) {
        switch (order[i]) {
            case 0:
                link_node(y, x, y - 1, x);
                break;
            case 1:
                link_node(y, x, y + 1, x);
                break;
            case 2:
                link_node(y, x, y, x - 1);
                break;
            case 3:
                link_node(y, x, y, x + 1);
                break;
            default:
                break;
        }
    }
}

//generates the spanning tree of size (GAME_HEIGHT / 2, GAME_WIDTH / 2), this is for creating the hamilton cycle order array next.
void generate_spanning_tree() {
    memset(spanning_tree, 0, sizeof spanning_tree);
    spanning_tree[0]->visited = true;
    link_node(0, 0, 0, 1);
}

//sets the node[y][x] to be visited
void set_visited(int y, int x) {
    spanning_tree[y][x].visited = true;
}
//checks if the node[y][x] is visited or not
bool is_visited(int y, int x) {
    return spanning_tree[y][x].visited;
}

void set_can_go_right(int y, int x) {
    spanning_tree[y][x].can_go_right = true;
}

void set_can_go_down(int y, int x) {
    spanning_tree[y][x].can_go_down = true;
}

/*
 * Generate the hamilton cycle order array.
 * If the num in the hamilton cycle order array of snake's front body is always ahead of the behind body one,
 * then as long as the snake go by the order, it will never collide with its body.
 */

void generate_hamilton_cycle() {
    //generate the spanning tree first to get a reference.
    generate_spanning_tree();
    memset(hamilton_cycle, 0, sizeof hamilton_cycle);
    int num = 0;
    int y = 0;
    int x = 0;
    node_direction direction = can_go_down(y, x) ? NODE_UP : NODE_LEFT;
    //if we haven't labeled all the order, then keeps the iteration.
    while(num != (WINDOW_HEIGHT - 2) * (WINDOW_WIDTH - 2)) {
        node_direction next_direction = find_next_direction(y, x, direction);
        switch (direction) {
            case NODE_UP:
                switch (next_direction) {
                    case NODE_UP:
                        hamilton_cycle[y*2+1][x*2] = num++;
                        hamilton_cycle[y*2][x*2] = num++;
                        break;
                    case NODE_DOWN:
                        hamilton_cycle[y*2+1][x*2] = num++;
                        hamilton_cycle[y*2][x*2] = num++;
                        hamilton_cycle[y*2][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        break;
                    case NODE_LEFT:
                        hamilton_cycle[y*2+1][x*2] = num++;
                        break;
                    case NODE_RIGHT:
                        hamilton_cycle[y*2+1][x*2] = num++;
                        hamilton_cycle[y*2][x*2] = num++;
                        hamilton_cycle[y*2][x*2+1] = num++;
                        break;
                }
                break;
            case NODE_DOWN:
                switch (next_direction) {
                    case NODE_UP:
                        hamilton_cycle[y*2][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2] = num++;
                        hamilton_cycle[y*2][x*2] = num++;
                        break;
                    case NODE_DOWN:
                        hamilton_cycle[y*2][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        break;
                    case NODE_LEFT:
                        hamilton_cycle[y*2][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2] = num++;
                        break;
                    case NODE_RIGHT:
                        hamilton_cycle[y*2][x*2+1] = num++;
                        break;
                }
                break;
            case NODE_LEFT:
                switch (next_direction) {
                    case NODE_UP:
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2] = num++;
                        hamilton_cycle[y*2][x*2] = num++;
                        break;
                    case NODE_DOWN:
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        break;
                    case NODE_LEFT:
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2] = num++;
                        break;
                    case NODE_RIGHT:
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2] = num++;
                        hamilton_cycle[y*2][x*2] = num++;
                        hamilton_cycle[y*2][x*2+1] = num++;
                        break;
                }
                break;
            case NODE_RIGHT:
                switch (next_direction) {
                    case NODE_UP:
                        hamilton_cycle[y*2][x*2] = num++;
                        break;
                    case NODE_DOWN:
                        hamilton_cycle[y*2][x*2] = num++;
                        hamilton_cycle[y*2][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        break;
                    case NODE_LEFT:
                        hamilton_cycle[y*2][x*2] = num++;
                        hamilton_cycle[y*2][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2+1] = num++;
                        hamilton_cycle[y*2+1][x*2] = num++;
                        break;
                    case NODE_RIGHT:
                        hamilton_cycle[y*2][x*2] = num++;
                        hamilton_cycle[y*2][x*2+1] = num++;
                        break;
                }
                break;
            default:
                break;
        }
        //update the index of the next node.
        direction = next_direction;
        switch (direction) {
            case NODE_UP:
                y--;
                break;
            case NODE_DOWN:
                y++;
                break;
            case NODE_LEFT:
                x--;
                break;
            case NODE_RIGHT:
                x++;
                break;
        }
    }
}

/* We always want to turn left based on the current direction if possible.
 * If not, then go straight, then go right, then take U turn.
 */

node_direction find_next_direction(int y, int x, node_direction cur_direction) {
    switch (cur_direction) {
        /*
         * OO
         * XO
         *
         * If the current direction is up, it always starts at the bottom left side, we need create the order by close to the spanning tree trunk.
         *
         * e.g.:
         *  OOO
         *  O--  for this case, we will go up and then turn right
         *  XOO
         */
        case NODE_UP:
            if(can_go_left(y, x)) {
                return NODE_LEFT;
            }
            if(can_go_up(y, x)) {
                return NODE_UP;
            }
            if(can_go_right(y, x)) {
                return NODE_RIGHT;
            }
            return NODE_DOWN;
        // If the current direction is down, it always starts at the top right side
        case NODE_DOWN:
            if(can_go_right(y, x)) {
                return NODE_RIGHT;
            }
            if(can_go_down(y, x)) {
                return NODE_DOWN;
            }
            if(can_go_left(y, x)) {
                return NODE_LEFT;
            }
            return NODE_UP;
        // If the current direction is left, it always starts at the bottom right side
        case NODE_LEFT:
            if(can_go_down(y, x)) {
                return NODE_DOWN;
            }
            if(can_go_left(y, x)) {
                return NODE_LEFT;
            }
            if(can_go_up(y, x)) {
                return NODE_UP;
            }
            return NODE_RIGHT;
        // If the current direction is down, it always starts at the top right side
        case NODE_RIGHT:
            if(can_go_up(y, x)) {
                return NODE_UP;
            }
            if(can_go_right(y, x)) {
                return NODE_RIGHT;
            }
            if(can_go_down(y, x)) {
                return NODE_DOWN;
            }
            return NODE_LEFT;
        default:
            return -1;
    }
}

bool can_go_up(int y, int x) {
    if(y == 0) {
        return false;
    }
    return can_go_down(y - 1, x);
}

bool can_go_down(int y, int x) {
    return spanning_tree[y][x].can_go_down;
}

bool can_go_left(int y, int x) {
    if(x == 0) {
        return false;
    }
    return can_go_right(y, x - 1);
}

bool can_go_right(int y, int x) {
    return spanning_tree[y][x].can_go_right;
}

//main function when ai_snake is playing
bool ai_snake_play(WINDOW *window) {
    init_game();
    while (!is_over && !is_win) {
        find_best_direction();
        run();
        print_map(window);
        usleep(1000);
    }
    return !is_over;
}

void find_best_direction() {
    int food_distance = get_distance(food);
    int tail_distance = get_distance(snake_tail);
    
    int max_jump_available = tail_distance - snake_size - 2;
    int empty_tile_count = MAP_SIZE - snake_size - 1;
    //if there's only 25% empty tile left, we will consider don't jump on the hamilton order
    if(empty_tile_count < MAP_SIZE * 3 / 4) {
        max_jump_available = 0;
    }

    //if we're already close to the food, we don't want jump over it.
    if(food_distance < max_jump_available) {
        max_jump_available = food_distance;
    }
    //calibrate it to be at least 0
    if( max_jump_available < 0) {
        max_jump_available = 0;
    }
    
    direction best_direction;
    int best_dist = -1;

    // check each of the position to see which of the best direction we should pick
    if(can_snake_move_right()) {
        int dist = get_distance_by_index(snake_head->y, snake_head->x + 1);
        if(dist <= max_jump_available && dist > best_dist) {
            best_dist= dist;
            best_direction = RIGHT;
        }
    }
    if(can_snake_move_left()) {
        int dist = get_distance_by_index(snake_head->y, snake_head->x - 1);
        if(dist <= max_jump_available && dist > best_dist) {
            best_dist= dist;
            best_direction = LEFT;
        }
    }
    if(can_snake_move_up()) {
        int dist = get_distance_by_index(snake_head->y - 1, snake_head->x);
        if(dist <= max_jump_available && dist > best_dist) {
            best_dist= dist;
            best_direction = UP;
        }
    }
    if(can_snake_move_down()) {
        int dist = get_distance_by_index(snake_head->y + 1, snake_head->x);
        if(dist <= max_jump_available && dist > best_dist) {
            best_dist= dist;
            best_direction = DOWN;
        }
    }
    //we choose this best direction as the snake direction for the next move.
    snake_direction = best_direction;
}

//get the distance from snake head to the given node in hamilton cycle order array
int get_distance(plist node) {
    int snake_head_index = hamilton_cycle[snake_head->y - 1][snake_head->x - 1];
    int destination_index = hamilton_cycle[node->y - 1][node->x - 1];
    if(snake_head_index < destination_index) {
        return destination_index - snake_head_index - 1;
    }
    return destination_index - snake_head_index + MAP_SIZE - 1;
}

//get the distance from snake head to coordinate(y,x) in hamilton cycle order array
int get_distance_by_index(int y, int x) {
    int snake_head_index = hamilton_cycle[snake_head->y - 1][snake_head->x - 1];
    int destination_index = hamilton_cycle[y - 1][x - 1];
    if(snake_head_index < destination_index) {
        return destination_index - snake_head_index - 1;
    }
    return destination_index - snake_head_index + MAP_SIZE - 1;
}




