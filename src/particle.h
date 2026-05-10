#ifndef PARTICLE
#define PARTICLE

#include "utils.h"
#include "setup.h"
#include <raylib.h>

typedef enum {
    ACIRCLE,
    ASQUARE,
    ATRIANGLE
} AtomShape;

typedef struct {
    float size;
    float lifeTime;
    Color color;
    AtomShape shape;
    Vector2 pos;
    Vector2 dir;
} Atom;


#endif
