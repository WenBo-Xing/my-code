#include "io.h"

int write_score() {
    //Update history score
    int new_score = snake_size - INIT_SNAKE_SIZE;
    int old_score = read_score();

    if(old_score >= new_score){
        return old_score;
    }

    FILE *fp = fopen(SCORE_OUT_FILENAME,"w");

    if(fp){
        fprintf(fp, "%d", new_score);
        fclose(fp);
    }
    return new_score;
}

int read_score(){
    int score = 0;
    FILE *fp = fopen(SCORE_OUT_FILENAME,"r");
    if(fp){
        fscanf(fp, "%d", &score);
        fclose(fp);
    }

    return score;
}

void read_stage() {
    FILE *fp = fopen(LEVEL_FILENAME, "r");
    if(fp) {
        fscanf(fp, "%d", &level_size);
        level_info = (int *) malloc(sizeof(int) * level_size);
        for(int i = 0; i < level_size; i++) {
            fscanf(fp, "%d", level_info + i);
        }
        fclose(fp);
    }
}