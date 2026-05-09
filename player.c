#include <raylib.h>
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
    printf("radius: %f\n", normBF(&p->mass));
    return p;
}

void updatePlayer(Player *p){
    p->radius = normBF(&p->mass) * 20 + 20;
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
}

