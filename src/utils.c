#include "utils.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

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

int sRandRange(int from, int to){
    int seed;
    int randi;
    FILE* urandom = fopen("/dev/urandom", "rb");
    if(urandom == NULL){
        perror("failed to read /dev/urandom\n");
    }
    fread(&seed, sizeof(seed), 1, urandom);
    fclose(urandom);
    srand(seed);
    randi = (rand());
    return randi;
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

Vector2 randDir(){
    
}
