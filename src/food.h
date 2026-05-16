#ifndef FOOD
#define FOOD

#include "player.h"
#include "utils.h"
#include "physic.h"
#include <raylib.h>

#define FOOD_MIN_RADIUS 10
#define FOOD_MAX_RADIUS 40
#define DRAIN_FACTOR 0.01

typedef struct {
    Color color;
    BoundedFloat drawRadius;
    Body body;
} Food;

Food* newRandFood();
void drawFoods(Food** foods, int amount);
Food** genRandFoods(int amount);
int checkFoodColision(Player* p, Food* f);
void updateFoods(Player* p, Food** fs, int fa);

#endif

