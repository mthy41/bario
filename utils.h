#ifndef UTILS
#define UTILS

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

unsigned int randRange(int from, int to);
Color randColor();

static inline float normBF(BoundedFloat* bf) {
    return (bf->value - bf->min)/(bf->max - bf->min);
}

#endif
