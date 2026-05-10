#ifndef FOOD
#define FOOD

#include "player.h"
#include "utils.h"
#include <raylib.h>

typedef struct {
    Color color;
    int radius;
    Vector2 pos;
    BoundedFloat mass;
    float speed;
    Vector2 dir;
} Food;

Food* newRandFood();
void drawFoods(Food** foods, int amount);
Food** genRandFoods(int amount);
int checkFoodColision(Player* p, Food* f);
void updateFoods(Player* p, Food** fs, int fa);

#endif

