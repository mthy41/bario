#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "setup.h"
#include "utils.h"

Player* newPlayerDefault(void){
    Player* p = (Player*) malloc(sizeof(Player));
    p->color = BLACK;
    p->pos.x = V_MID;
    p->pos.y = H_MID;
    p->speed = 4;
    p->score = START_POINTS;
    p->mass.value = 11.;
    p->mass.max = 40.;
    p->mass.min = 10.;
    p->radius = (normBF(&p->mass) * 20) + 20;
    return p;
}

static void printPStatus(Player* p){
    printf("mass:  %f\nspeed: %f\n ", p->mass.value, p->speed);
}

static void drain(Player* p){
    const float drainFactor = 0.5;
    if(p->mass.value - drainFactor > p->mass.min){
        p->mass.value -= drainFactor;
        return;
    }
    p->mass.value = p->mass.min;
}


void updatePlayer(Player *p){
    p->radius = normBF(&p->mass) * 20 + 20;

    int currentSpeed = p->speed;
    if(IsKeyDown(KEY_LEFT_SHIFT)){
        drain(p);
        p->speed *= 2;
    }

    if(IsKeyDown(KEY_S)){
        p->pos.y += p->speed;
    }
    if(IsKeyDown(KEY_W)){
        p->pos.y -= p->speed;
    }
    if(IsKeyDown(KEY_D)){
        p->pos.x += p->speed;
    }
    if(IsKeyDown(KEY_A)){
        p->pos.x -= p->speed;
    }
    
    p->speed = currentSpeed;

    #ifdef DEBUG
    if(IsKeyPressed(KEY_I)){
        printPStatus(p);
    }
    #endif
}

