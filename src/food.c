#include <raylib.h>
#include <stdlib.h>

#include "food.h"
#include "player.h"
#include "setup.h"
#include "utils.h"

Food *newRandFood() {
    Food *f = (Food *)malloc(sizeof(Food));
    f->color = randColor();
    f->mass.max = 40;
    f->mass.min = 20;
    f->mass.value = randRange(f->mass.min, f->mass.max);
    f->radius = (normBF(&f->mass) * 20) + 10;

    #ifdef DEBUG
    printf("normlized value: %f\n", normBF(&f->mass));
    printf("normlized radius with 30: %d\n", f->radius);
    #endif

    int bound = f->radius * 2;
    f->pos.y = randRange(bound, SCREEN_HEIGHT - bound);
    f->pos.x = randRange(bound, SCREEN_WIDTH - bound);

    return f;
}

Food** genRandFoods(int amount){
    Food** fArr = malloc(sizeof(Food*)*amount);
    for(int i=0; i<amount; i++){
        fArr[i] = newRandFood();
    }
    return fArr;
}

void drawFoods(Food **foods, int amount) {
    for (int i = 0; i < amount; i++) {
        if(foods[i] == NULL) continue;
        DrawCircle(foods[i]->pos.x, foods[i]->pos.y, foods[i]->radius,
                   foods[i]->color);
    }
}

int checkFoodColision(Player* p, Food *f){
    int touch = CheckCollisionCircles(f->pos, f->radius, p->pos, p->radius - f->radius);
    return (touch && p->radius >= f->radius);
}

static void tintFoods(Food** fs, int fa, Color c){
    for (int i=0; i<fa; i++){
        if (fs[i] == NULL) continue;
        fs[i]->color = c;
    }
}

static void printFoodsInfo(Food** fs, int fa){
    printf("\n----- food coords -----\n");
    for (int i=0; i<fa; i++){
        if (fs[i] == NULL) continue;
        printf("food %d: x.%f, y.%f\n, r.%d", i, fs[i]->pos.x, fs[i]->pos.y, fs[i]->radius);
    }
}

static void drain(Food* f){
    const float drainFactor = 0.01;
    if((f->mass.value - drainFactor) > f->mass.min){
        f->mass.value -= drainFactor;
    } else { f->mass.value = f->mass.min; }
}

void updateFoods(Player* p, Food** fs, int fa){
    for (int i=0; i<fa; i++){
        if (fs[i] == NULL) continue;
        if (checkFoodColision(p, fs[i])){
            p->score++;
            p->mass.value += fs[i]->mass.value * 0.2;
            free(fs[i]);
            fs[i] = NULL;
            continue;
        }
        drain(fs[i]);
        fs[i]->radius = (normBF(&fs[i]->mass) * 20) + 20;
    }

    #ifdef DEBUG
    if (IsKeyPressed(KEY_T)){
        tintFoods(fs, fa, RED);
    }

    if (IsKeyPressed(KEY_P)){
        printFoodsInfo(fs, fa);
    }
    #endif
}
