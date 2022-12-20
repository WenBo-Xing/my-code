cmake_minimum_required(VERSION 3.24)
project(snakeGame C)


add_executable(snakeGame main.c snake.h snake.c snake_ai.c snake_ai.h io.h io.c)

target_link_libraries(snakeGame ncurses)
