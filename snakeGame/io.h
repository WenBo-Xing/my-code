#ifndef SNAKEGAME_IO_H
#define SNAKEGAME_IO_H

#include "snake_ai.h"
#define SCORE_OUT_FILENAME "score.txt"
#define LEVEL_FILENAME "level.txt"

int write_score();
int read_score();
void read_stage();
#endif //SNAKEGAME_IO_H
