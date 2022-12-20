#include <curses.h>
#include "snake.h"
#include "snake_ai.h"
#include "io.h"


#define ENTER 10

/*

 $$$$$$\  $$\   $$\  $$$$$$\  $$\   $$\ $$$$$$$$\
$$  __$$\ $$$\  $$ |$$  __$$\ $$ | $$  |$$  _____|
$$ /  \__|$$$$\ $$ |$$ /  $$ |$$ |$$  / $$ |
\$$$$$$\  $$ $$\$$ |$$$$$$$$ |$$$$$  /  $$$$$\
 \____$$\ $$ \$$$$ |$$  __$$ |$$  $$<   $$  __|
$$\   $$ |$$ |\$$$ |$$ |  $$ |$$ |\$$\  $$ |
\$$$$$$  |$$ | \$$ |$$ |  $$ |$$ | \$$\ $$$$$$$$\
 \______/ \__|  \__|\__|  \__|\__|  \__|\________|

*/

/*
 $$$$$$\   $$$$$$\  $$\      $$\ $$$$$$$$\
$$  __$$\ $$  __$$\ $$$\    $$$ |$$  _____|
$$ /  \__|$$ /  $$ |$$$$\  $$$$ |$$ |
$$ |$$$$\ $$$$$$$$ |$$\$$\$$ $$ |$$$$$\
$$ |\_$$ |$$  __$$ |$$ \$$$  $$ |$$  __|
$$ |  $$ |$$ |  $$ |$$ |\$  /$$ |$$ |
\$$$$$$  |$$ |  $$ |$$ | \_/ $$ |$$$$$$$$\
 \______/ \__|  \__|\__|     \__|\________|

*/

typedef enum mode {
    AI_PLAY,
    PLAYER_PLAY,
    QUIT
} game_mode;

WINDOW* main_window;

//initialize ncurses
void init() {
    initscr();
    start_color();
    noecho();
    curs_set(0);
    srand(time(NULL));
    read_stage();
    refresh();
}

//initializes the parent main window
WINDOW* init_main_window(int height, int width, int start_y, int start_x) {
    main_window = newwin(height, width, start_y, start_x);
    box(main_window, ACS_VLINE, ACS_HLINE);
    wrefresh(main_window);
    keypad(main_window, true);

    return main_window;
}

//displays menu window and returns the play mode user choose
game_mode draw_scroll_menu(WINDOW* menu_window) {
    keypad(menu_window, true);

    mvwprintw(menu_window, 1, 5, " $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$\\   $$\\ $$$$$$$$\\");
    mvwprintw(menu_window, 2, 5, "$$  __$$\\ $$$\\  $$ |$$  __$$\\ $$ | $$  |$$  _____|");
    mvwprintw(menu_window, 3, 5, "$$ /  \\__|$$$$\\ $$ |$$ /  $$ |$$ |$$  / $$ |");
    mvwprintw(menu_window, 4, 5, "\\$$$$$$\\  $$ $$\\$$ |$$$$$$$$ |$$$$$  /  $$$$$\\");
    mvwprintw(menu_window, 5, 5, " \\____$$\\ $$ \\$$$$ |$$  __$$ |$$  $$<   $$  __|");
    mvwprintw(menu_window, 6, 5, "$$\\   $$ |$$ |\\$$$ |$$ |  $$ |$$ |\\$$\\  $$ |");
    mvwprintw(menu_window, 7, 5, "\\$$$$$$  |$$ | \\$$ |$$ |  $$ |$$ | \\$$\\ $$$$$$$$\\");
    mvwprintw(menu_window, 8, 5, " \\______/ \\__|  \\__|\\__|  \\__|\\__|  \\__|\\________|");

    mvwprintw(menu_window, 10, 7, " $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\");
    mvwprintw(menu_window, 11, 7, "$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|");
    mvwprintw(menu_window, 12, 7, "$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |");
    mvwprintw(menu_window, 13, 7, "$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\");
    mvwprintw(menu_window, 14, 7, "$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|");
    mvwprintw(menu_window, 15, 7, "$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |");
    mvwprintw(menu_window, 16, 7, "\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\");
    mvwprintw(menu_window, 17, 7, " \\______/ \\__|  \\__|\\__|     \\__|\\________|");

    mvwprintw(menu_window, 27, 20, "Press Enter to play");
    char * menu_arr[] = {"AI-play", "Player-play", "Quit"};
    int count = 3;
    int choice = 0;
    int key;
    wrefresh(menu_window);
    while(TRUE) {
        for(int i = 0; i < count; i++) {
            if(i == choice) {
                wattron(menu_window, A_STANDOUT);
            }
            mvwprintw(menu_window, i * 2 + 20, 25, menu_arr[i]);
            wattroff(menu_window, A_STANDOUT);
        }
        key = wgetch(menu_window);
        switch (key) {
            case KEY_UP:
                choice = (choice + count - 1) % count;
                break;
            case KEY_DOWN:
                choice = (choice + 1) % count;
                break;
            case ENTER:
                return choice;
            default:
                break;
        }
    }
}

void draw_game_end_window_for_ai(WINDOW* window, bool game_status) {
    mvwprintw(window, 10, 20, game_status ? "AI wins." : "AI loses.");
    mvwprintw(window, 20, 10, "Press any key to go to the main menu.");
    wrefresh(window);
}

void draw_game_end_window_for_player(WINDOW* window, bool game_status) {
    mvwprintw(window, 10, 20, game_status ? "You win." : "You lose.");
    mvwprintw(window, 12, 20, "game score: %d.", snake_size - INIT_SNAKE_SIZE);
    int highest_score = write_score();
    mvwprintw(window, 13, 20, "highest score: %d.", highest_score);
    mvwprintw(window, 20, 10, "Press any key to go to the main menu.");
    wrefresh(window);
}

//entrance function for snake ai-play mode
void ai_play() {
    generate_hamilton_cycle();
    WINDOW *game_window = subwin(main_window,SUB_WINDOW_HEIGHT, SUB_WINDOW_WIDTH, SUB_WINDOW_START_Y, SUB_WINDOW_START_X);
    bool status = ai_snake_play(game_window);
    werase(game_window);
    delwin(game_window);
    wrefresh(main_window);
    WINDOW *end_game_window = subwin(main_window,SUB_WINDOW_HEIGHT, SUB_WINDOW_WIDTH, SUB_WINDOW_START_Y, SUB_WINDOW_START_X);
    draw_game_end_window_for_ai(end_game_window, status);
    usleep(1000000);
    getch();
    werase(end_game_window);
    delwin(end_game_window);

}

//entrance function for snake player-play mode
void player_play() {
    WINDOW *game_window = subwin(main_window,SUB_WINDOW_HEIGHT, SUB_WINDOW_WIDTH, SUB_WINDOW_START_Y, SUB_WINDOW_START_X);
    keypad(game_window, true);
    bool status = player_snake_play(game_window);
    werase(game_window);
    delwin(game_window);
    wrefresh(main_window);
    WINDOW *end_game_window = subwin(main_window,SUB_WINDOW_HEIGHT, SUB_WINDOW_WIDTH, SUB_WINDOW_START_Y, SUB_WINDOW_START_X);
    draw_game_end_window_for_player(end_game_window, status);
    usleep(1000000);
    getch();
    werase(end_game_window);
    delwin(end_game_window);
}
int main() {
    init();
    refresh();
    main_window = init_main_window(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_START_Y, WINDOW_START_X);
    if(main_window == NULL) {
        printw("window size is too small. Press any key to quit.");
        getch();
        endwin();
        return -1;
    }

    //game main loop start
    while(true) {
        WINDOW* menu_window = subwin(main_window, SUB_WINDOW_HEIGHT, SUB_WINDOW_WIDTH, SUB_WINDOW_START_Y, SUB_WINDOW_START_X);
        game_mode choice = draw_scroll_menu(menu_window);
        wclear(menu_window);
        delwin(menu_window);
        switch (choice) {
            case AI_PLAY:
                ai_play();
                break;
            case PLAYER_PLAY:
                player_play();
                break;
            case QUIT:
                if(level_info != NULL) {
                    free(level_info);
                }
                delwin(main_window);
                endwin();
                return 0;
            default:
                break;
        }
    }
    //unreachable place
    return -1;
}
