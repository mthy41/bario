#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "physic.h"
#include "setup.h"
#include "utils.h"

Player* newPlayerDefault(void){
    Player* p = (Player*) malloc(sizeof(Player));
    p->color = BLACK;
    p->body.pos.x = V_MID;
    p->body.pos.y = H_MID;
    p->body.speed.x = 4;
    p->body.speed.y = 4;
    p->score = START_POINTS;
    p->body.mass.value = 11.;
    p->body.mass.max = 40.;
    p->body.mass.min = 10.;
    p->body.hitboxRadius = scaleRadius(&p->body, 20.0f);
    return p;
}

static void printPStatus(Player* p){
    printf("mass:  %f\nspeed: %f\n ", p->body.mass.value, p->body.speed.x);
}

static void drain(Player* p){
    const float drainFactor = 0.5;
    if(p->body.mass.value - drainFactor > p->body.mass.min){
        p->body.mass.value -= drainFactor;
        return;
    }
    p->body.mass.value = p->body.mass.min;
}


void updatePlayer(Player *p){
    updateHitBoxRadius(&p->body, 10, 100);

    Vector2 currentSpeed = p->body.speed;
    if(IsKeyDown(KEY_LEFT_SHIFT)){
        drain(p);
        scalar(&p->body.speed, 2);
    }

    if(IsKeyDown(KEY_S)){
        p->body.pos.y += p->body.speed.y;
    }
    if(IsKeyDown(KEY_W)){
        p->body.pos.y -= p->body.speed.y;
    }
    if(IsKeyDown(KEY_D)){
        p->body.pos.x += p->body.speed.x;
    }
    if(IsKeyDown(KEY_A)){
        p->body.pos.x -= p->body.speed.x;
    }
    
    p->body.speed = currentSpeed;

    #ifdef DEBUG
    if(IsKeyPressed(KEY_I)){
        printPStatus(p);
    }
    #endif
}

