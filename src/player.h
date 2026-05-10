#ifndef PLAYER
#define PLAYER
#include "utils.h"
#include <raylib.h>

typedef struct {
    Color color;
    int radius;
    char** nickname;
    Vector2 pos;
    float speed;
    int score;
    BoundedFloat mass;
} Player;

Player* newPlayerDefault(void);
void updatePlayer(Player* p);

#endif
