#include <raylib.h>
#include <cmath>
#include "game.h"

Game::Game()
{
    camera.target = player.GetPlayerPosition();
    camera.offset = Vector2{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    camera.rotation = 0;
    camera.zoom = 1;

    int x, y;
    for(int i = 0; i < 240; i++)
    {
        x = i%16 * 32 + 16;
        y = floor(i/16) * 32 + 16;
        tile.AddTile(TileData{(float)x, (float)y}, i);
    }
}

void Game::Draw()
{
    BeginMode2D(camera);

    for(int i = 0; i < 240; i++) tile.Draw(i);
    player.Draw();

    EndMode2D();
}

void Game::Update()
{
    player.Update();
    camera.target = player.GetPlayerPosition();
}
