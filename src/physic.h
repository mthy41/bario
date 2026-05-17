#ifndef PHYSIC
#define PHYSIC

#include <raylib.h>
#include <raymath.h>
#include "setup.h"
#include "utils.h"

typedef enum {
    COLISION_ABSENT,
    COLISION_TOUCH,
    COLISION_OVERSHOOT
} Collision;

typedef struct {
    Vector2 pos;
    Vector2 speed;
    BoundedFloat mass;
    float hitboxRadius;
} Body;

float scaleRadius(Body* b, float scaleFactor);

void updateHitBoxRadius(Body* b, float min, float max);

float randBodyMass(BoundedFloat* bf);

void scalar(Vector2* f, float s);

void move2DWithCollision(Vector2 *v, float step, Vector2* d, float colisionRadius);

    Collision windowRightXCollision(Body* b);

    Collision windowLeftXCollision(Body* b);

    Collision windowBotYCollision(Body* b);

    Collision windowTopYCollision(Body* b);

#endif
