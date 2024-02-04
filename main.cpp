#include <raylib.h>

//Configuration Variables
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 480;
const int GAME_FPS = 60;
const char* GAME_TITLE = "Survival Game Test";

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(GAME_FPS);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
