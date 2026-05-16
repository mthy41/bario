#include <raylib.h>
#include <stddef.h>
#include <stdio.h>
#include "player.h"
#include "food.h"
#include "setup.h"


void drawScore(int* score){
    char str[20];
    sprintf(str, "%d", *score);
    DrawText(str, SCREEN_WIDTH/2, 20, 50*SCALE_FACTOR, RAYWHITE);
}

void draw(Player* p, Food** foods, int fa)
{
   BeginDrawing();
        ClearBackground(PURPLE);
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GRAY);
        drawScore(&p->score);
        
        //Food
        drawFoods(foods, fa);

        //Player
        DrawCircle(p->body.pos.x, p->body.pos.y, p->body.hitboxRadius, p->color);

    EndDrawing();
}

void update(Player* p, Food** fs, int fa)
{
    updatePlayer(p);
    updateFoods(p, fs, fa);
}

int main(void){
    const int WINDOWS_OFFSET = 0;

    InitWindow(SCREEN_WIDTH+WINDOWS_OFFSET, SCREEN_HEIGHT+WINDOWS_OFFSET, "Hi!");
    SetTargetFPS(TARGET_FPS);

    Player* p = newPlayerDefault();
    Food** foods = genRandFoods(30);

    while(!WindowShouldClose())
    {
        draw(p, foods, 30);
        update(p, foods, 30);
    }

    CloseWindow();

    return 0;
}
