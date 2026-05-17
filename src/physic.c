#include "physic.h"
#include "setup.h"
#include "utils.h"
#include <math.h>
#include <raylib.h>

float randBodyMass(BoundedFloat* bf){
    return randRange(bf->min, bf->max);
}

void scalar(Vector2* v, float s){
    v->x *= s;
    v->y *= s;
}

float scaleRadius(Body* b, float scaleFactor) {
    return boundedFloatNorm(&b->mass) * scaleFactor;
} 

void updateHitBoxRadius(Body* b, float min, float max){
    b->hitboxRadius = fmin(scaleRadius(b, max) + min, max);
}

Collision windowRightXCollision(Body* b){
    float point = b->pos.x + b->hitboxRadius;
    if(point <  SCREEN_WIDTH) return COLISION_ABSENT;
    if(point == SCREEN_WIDTH) return COLISION_TOUCH;
    return COLISION_OVERSHOOT;
}

Collision windowLeftXCollision(Body* b){
    float point = b->pos.x - b->hitboxRadius;
    if(point >  0) return COLISION_ABSENT;
    if(point == 0) return COLISION_TOUCH;
    return COLISION_OVERSHOOT;
}

Collision windowBotYCollision(Body* b){
    float point = b->pos.y + b->hitboxRadius;
    if(point <  SCREEN_HEIGHT) return COLISION_ABSENT;
    if(point == SCREEN_HEIGHT) return COLISION_TOUCH;
    return COLISION_TOUCH;
}

Collision windowTopYCollision(Body* b){
    float point = b->pos.y - b->hitboxRadius;
    if(point >  0) return COLISION_ABSENT;
    if(point == 0) return COLISION_TOUCH;
    return COLISION_OVERSHOOT;
}

