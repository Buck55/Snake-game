#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "Colors.h"

using namespace std;

int cellSize = 25;
int cellCount = 35;
int offset = 55;

int main()
{
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Black Mamba");
    SetTargetFPS(60);

    Texture2D logo = LoadTexture("Graphics/mamba.png");

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        game.HandleInput();
        game.Update();

        //Drawing
        ClearBackground(purple);

        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, black);
        DrawText ("Black Mamba", offset - 5, 12, 30, gold);
        DrawTexture(logo, offset + 200, 12, gold);

        DrawText ("Score", offset - 5, offset + cellSize * cellCount + 10, 30, gold);
        DrawText (TextFormat("%i", game.score), offset + 100, offset + cellSize * cellCount + 10, 30, gold);

        DrawText ("WASD/Arrow Keys", offset + 250, offset + cellSize * cellCount + 10, 30, gold);

        float speedInMilliseconds = game.speed * 1000;
        DrawText ("Speed", offset + 680, offset + cellSize * cellCount + 10, 30, gold);
        DrawText (TextFormat("%.2f", speedInMilliseconds), offset + 780, offset + cellSize * cellCount + 10, 30, gold);

        game.Draw();

        EndDrawing();
    }

    UnloadTexture(logo);

    CloseWindow();
    return 0;
}