#include <raylib.h>
#include <stdlib.h>
#include <math.h>

#include "food.h"
#include "physic.h"
#include "player.h"
#include "setup.h"
#include "utils.h"

Food *newRandFood() {
    Food *f = (Food *)malloc(sizeof(Food));
    f->color = randColor();
    
    f->body.mass.max = 40;
    f->body.mass.min = 20;
    f->body.mass.value = randBodyMass(&f->body.mass);
    f->body.speed = randDir(); scalar(&f->body.speed, randRange(1, 4));
    f->body.hitboxRadius = fmin(scaleRadius(&f->body, FOOD_MAX_RADIUS) + FOOD_MIN_RADIUS, FOOD_MAX_RADIUS);

    float bound = f->body.hitboxRadius * 2;
    f->body.pos.x = randRange(bound, SCREEN_WIDTH - bound);
    f->body.pos.y = randRange(bound, SCREEN_HEIGHT - bound);

#ifdef DEBUG
  TODO
#endif

    return f;
}

Food **genRandFoods(int amount) {
    Food **fArr = malloc(sizeof(Food *) * amount);
    for (int i = 0; i < amount; i++) {
        fArr[i] = newRandFood();
    }
    return fArr;
}

void drawFoods(Food **foods, int amount) {
    for (int i = 0; i < amount; i++) {
        if (foods[i] == NULL)
            continue;
        DrawCircle(foods[i]->body.pos.x, foods[i]->body.pos.y, 
                   foods[i]->body.hitboxRadius, foods[i]->color);
    }
}

int checkFoodCollision(Player *p, Food *f) {
  int touch = CheckCollisionCircles(f->body.pos, 
                                    f->body.hitboxRadius, 
                                    p->body.pos, 
                                    p->body.hitboxRadius - f->body.hitboxRadius);
  return (touch && p->body.hitboxRadius >= f->body.hitboxRadius);
}

static void tintFoods(Food **fs, int fa, Color c) {
  for (int i = 0; i < fa; i++) {
    if (fs[i] == NULL)
      continue;
    fs[i]->color = c;
  }
}

static void printFoodsInfo(Food **fs, int fa) {
  printf("\n----- food coords -----\n");
  for (int i = 0; i < fa; i++) {
    if (fs[i] == NULL)
      continue;
    printf("food %d: x.%f, y.%f\n, r.%f", i, fs[i]->body.pos.x, fs[i]->body.pos.y,
           fs[i]->body.hitboxRadius);
  }
}

static void drain(Food *f) {
  if ((f->body.mass.value - DRAIN_FACTOR) > f->body.mass.min) {
    f->body.mass.value -= DRAIN_FACTOR;
  } else {
    f->body.mass.value = f->body.mass.min;
  }
}

void updateFoods(Player *p, Food **fs, int fa) {
  for (int i = 0; i < fa; i++) {
    if (fs[i] == NULL)
      continue;
    if (checkFoodCollision(p, fs[i])) {
      p->score++;
      p->body.mass.value += fs[i]->body.mass.value * 0.2;
      free(fs[i]);
      fs[i] = NULL;
      continue;
    }

    drain(fs[i]);
    updateHitBoxRadius(&fs[i]->body, FOOD_MIN_RADIUS, FOOD_MAX_RADIUS);

    if (windowRightXCollision(&fs[i]->body)) {
      fs[i]->body.speed.x *= -1;
    }

    if (windowLeftXCollision(&fs[i]->body)) {
      fs[i]->body.speed.x *= -1;
    }

    if (windowBotYCollision(&fs[i]->body)) {
      fs[i]->body.speed.y *= -1;
    }

    if (windowTopYCollision(&fs[i]->body)) {
      fs[i]->body.speed.y *= -1;
    }

    fs[i]->body.pos.x += fs[i]->body.speed.x;
    fs[i]->body.pos.y += fs[i]->body.speed.y;
  }

#ifdef DEBUG
  if (IsKeyPressed(KEY_T)) {
    tintFoods(fs, fa, RED);
  }

  if (IsKeyPressed(KEY_P)) {
    printFoodsInfo(fs, fa);
  }
#endif
}
