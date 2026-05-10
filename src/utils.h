#ifndef UTILS
#define UTILS

#include "setup.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#define DEBUG

typedef struct {
    float value;
    float min;
    float max;
} BoundedFloat;

typedef float sec_float;

unsigned int randRange(int from, int to);
Color randColor();
Vector2 randDir();

static inline float normBF(BoundedFloat* bf) {
    return (bf->value - bf->min)/(bf->max - bf->min);
}

static inline unsigned int secToFrames(sec_float secs){
    float tf = (float)TARGET_FPS;
    return (secs/tf);
}

#endif
