#include "snake.h"

plist snake_head, snake_tail, food;
tile map[WINDOW_HEIGHT][WINDOW_WIDTH];
direction snake_direction;
int snake_size;
int snake_level;
bool is_win, is_over;
int* level_info;
int level_size;
int interval;

//initializes snake
void init_snake() {
    snake_size = INIT_SNAKE_SIZE;
    snake_tail = (plist) malloc(sizeof(list));
    snake_tail->x = 1;
    snake_tail->y = 1;
    snake_tail->next = NULL;
    plist next = snake_tail;
    for(int i = 2; i <= INIT_SNAKE_SIZE; i++) {
        plist snake = (plist) malloc(sizeof (list));
        snake->x = i;
        snake->y = 1;
        snake->next = next;
        next = snake;
    }
    snake_head = next;

    plist current = snake_head;
    plist previous = NULL;
    while( current != NULL) {
        current->previous = previous;
        previous = current;
        current = current->next;
    }
    snake_direction = RIGHT;
}

//initializes game map
void init_map() {
    memset(map, 0, sizeof map);
    for(int i = 0; i < WINDOW_HEIGHT; i++) {
        for(int j = 0; j < WINDOW_WIDTH; j++) {
            if( i == 0 || j == 0 || i == WINDOW_HEIGHT - 1 || j == WINDOW_WIDTH - 1) {
                map[i][j] = WALL;
            } else if (i == 1 && j >= 2 && j <= 3) {
                map[i][j] = SNAKE_BODY;
            } else if (i == 1 && j == 4) {
                map[i][j] = SNAKE_HEAD;
            } else if (i == 1 && j == 1) {
                map[i][j] = SNAKE_TAIL;
            }
            else {
                map[i][j] = EMPTY;
            }
        }
    }
}

//generates food in a new random place
void create_food() {
    if(snake_size >= MAP_SIZE) {
        food->x = -1;
        food->y = -1;
        return;
    }
    int x, y;
    do {
        x = rand() % WINDOW_WIDTH;
        y = rand() % WINDOW_HEIGHT;
    } while (map[y][x] != EMPTY);
    food->x = x;
    food->y = y;
    map[y][x] = FOOD;
}

//initializes game variables
void init_game() {
    is_over = false;
    is_win = false;
    init_snake();
    init_map();
    init_food();
    snake_level = 1;
    interval = level_info[0];
}

//initializes food
void init_food() {
    food = (plist) malloc(sizeof (list));
    food->next = NULL;
    create_food();
}

//prints the map to the game window
void print_map(WINDOW *window) {
    for(int i = 1; i < WINDOW_HEIGHT - 1; i++) {
        for(int j = 1; j < WINDOW_WIDTH; j++) {
            switch (map[i][j]) {
                case SNAKE_HEAD:
                case SNAKE_BODY:
                case SNAKE_TAIL:
                    mvwaddch(window, i - 1, j - 1, SNAKE_MARK);
                    break;
                case FOOD:
                    mvwaddch(window, i - 1, j - 1, FOOD_MARK);
                    break;
                case EMPTY:
                    mvwaddch(window, i - 1, j - 1, ' ');
                    break;
                default:
                    break;
            }
        }
        wrefresh(window);
    }
}

//handles when snake eats the food
void eat_food() {
    update_snake_head();
    snake_size++;
}

//checks if snake can move to the next place based on the current snake direction
bool can_snake_move() {
    int next_x, next_y;
    get_next_loc(&next_y, &next_x);
    tile next_tile = map[next_y][next_x];
    return next_tile != WALL && next_tile != SNAKE_BODY;
}

//move the snake by one frame
void move_snake() {
    update_snake_head();
    update_snake_tail();
}

//gets the next location(y,x) in front of the snake
void get_next_loc(int* y, int* x) {
    int next_x = snake_head->x;
    int next_y = snake_head->y;
    switch (snake_direction) {
        case UP:
            next_y--;
            break;
        case DOWN:
            next_y++;
            break;
        case LEFT:
            next_x--;
            break;
        case RIGHT:
            next_x++;
            break;
        default:
            break;
    }
    *y = next_y;
    *x = next_x;
}

//move snake head to location in front of it and links the new head to the body
void update_snake_head() {
    int next_x, next_y;
    get_next_loc(&next_y, &next_x);
    
    map[snake_head->y][snake_head->x] = SNAKE_BODY;
    map[next_y][next_x] = SNAKE_HEAD;

    plist new_head = (plist) malloc(sizeof (list));
    new_head->y = next_y;
    new_head->x = next_x;
    new_head->next = snake_head;
    new_head->previous = NULL;
    snake_head->previous = new_head;
    snake_head = new_head;
}

//remove the snake tail and point to the new tail of the snake
void update_snake_tail() {
    plist new_tail = snake_tail->previous;
    map[snake_tail->y][snake_tail->x] = EMPTY;
    map[new_tail->y][new_tail->x] = SNAKE_TAIL;

    new_tail->next = NULL;
    free(snake_tail);
    snake_tail = new_tail;
}

/*
 * Run the game by one frame. If snake eats all the food, then player wins.
 * If snake touches the wall or it's body, then game is over.
 * If snake eats the food, then update the snake and generates a new food in a random place.
 * Otherwise, moves the snake forward.
 */
void run() {
    if(snake_size >= MAP_SIZE) {
        is_win = true;
        return;
    }
    if(!can_snake_move()) {
        is_over = true;
        return;
    }
    int next_x, next_y;
    get_next_loc(&next_y, &next_x);
    if(map[next_y][next_x] == FOOD) {
        eat_food();
        create_food();
        return;
    }
    move_snake();
}

//handles user input during the game
void handle_key_input(int key) {
    switch (key) {
        case KEY_UP:
            snake_direction = UP;
            break;
        case KEY_DOWN:
            snake_direction = DOWN;
            break;
        case KEY_LEFT:
            snake_direction = LEFT;
            break;
        case KEY_RIGHT:
            snake_direction = RIGHT;
            break;
        default:
            break;
    }
}

//main function when player plays the game. If game is over of player wins, return true. False otherwise.
bool player_snake_play(WINDOW *window) {
    init_game();
    nodelay(window, true);

    while(!is_over && !is_win) {
        handle_key_input(wgetch(window));
        run();
        print_map(window);
        change_level();
        mvprintw(WINDOW_END_Y, WINDOW_START_X, "SCORE: %d   LEVEL: %d", snake_size - INIT_SNAKE_SIZE, snake_level);
        refresh();
        usleep(interval);
    }
    free_all();
    move(WINDOW_END_Y, 0);
    clrtoeol();
    return !is_over;
}

//checks if the snake can move up.
bool can_snake_move_up() {
    direction cur_direction = snake_direction;
    snake_direction = UP;
    bool result = false;
    if(can_snake_move()) {
        result = true;
    }
    snake_direction = cur_direction;
    return result;
}

//checks if the snake can move down.
bool can_snake_move_down() {
    direction cur_direction = snake_direction;
    snake_direction = DOWN;
    bool result = false;
    if(can_snake_move()) {
        result = true;
    }
    snake_direction = cur_direction;
    return result;
}

//checks if the snake can move left.
bool can_snake_move_left() {
    direction cur_direction = snake_direction;
    snake_direction = LEFT;
    bool result = false;
    if(can_snake_move()) {
        result = true;
    }
    snake_direction = cur_direction;
    return result;
}

//checks if the snake can move right.
bool can_snake_move_right() {
    direction cur_direction = snake_direction;
    snake_direction = RIGHT;
    bool result = false;
    if(can_snake_move()) {
        result = true;
    }
    snake_direction = cur_direction;
    return result;
}

//free all pointer variables
void free_all() {
    plist node = snake_head;
    while(node != NULL) {
        plist next = node->next;
        free(node);
        node = next;
    }
    free(food);
    snake_head = NULL;
    snake_tail = NULL;
    food = NULL;
}

//change the level based on player's score
void change_level() {
    int score = snake_size - INIT_SNAKE_SIZE;
    if(score > 5 && score <= 10) {
        interval = level_info[1];
        snake_level = 2;
    } else if (score > 10) {
        interval = level_info[2];
        snake_level = 3;
    }
}


