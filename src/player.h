#ifndef PLAYER
#define PLAYER
#include "physic.h"
#include "utils.h"
#include <raylib.h>

typedef struct {
    Color color;
    char** nickname;
    int score;
    Body body;
} Player;

Player* newPlayerDefault(void);
void updatePlayer(Player* p);

#endif
