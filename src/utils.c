#include "utils.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int randRange(int from, int to){
    unsigned int seed;
    unsigned int randui;
    FILE* urandom = fopen("/dev/urandom", "rb");
    if(urandom == NULL){
        perror("failed to read /dev/urandom\n");
    }
    fread(&seed, sizeof(seed), 1, urandom);
    fclose(urandom);
    srand(seed);
    randui = (rand() % (to - from) + from);
    return randui;
}

int randSign(){
    return randRange(0, 2) ? -1 : 1;
}

Color randColor(){
    Color c = {
        .a = 255,
        .r = randRange(0, 255),
        .g = randRange(0, 255),
        .b = randRange(0, 255)
    };
    return c;
}

void printVector2(Vector2* v){
    printf("x: %f, y: %f\n", v->x, v->y);
}

Vector2 randDir(){
    Vector2 v = {.x = 0.0f, .y = 1.0f};
    v = Vector2Rotate(v, randRange(0, PI*2));
    return v;
}
