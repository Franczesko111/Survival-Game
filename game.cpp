#include <iostream>
#include <raylib.h>
#include <cmath>
#include "game.h"
using namespace std;

Game::Game()
{
    camera.target = player.GetPlayerPosition();
    camera.offset = Vector2{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    camera.rotation = 0;
    camera.zoom = 0.5;

    int x, y;
    for(int i = 0; i < 380; i++)
    {
        x = (i%20 * 32 + 16) - 64;
        y = (floor(i/20) * 32 + 16) - 64;
        tile.AddTile(TileData{x, y}, i);
    }
}

void Game::Draw()
{
    BeginMode2D(camera);

    for(int i = 0; i < 380; i++) tile.Draw(i);
    player.Draw();

    EndMode2D();
}

void Game::Update()
{
    for(int i = 0; i < 380; i++) tile.Update(i, camera.target.x);
    player.Update();
    camera.target = player.GetPlayerPosition();
}
