#include <raylib.h>
#include <cmath>
#include "game.h"

Game::Game()
{
    int x, y;
    for(int i = 0; i < 240; i++)
    {
        x = i%16 * 32 + 16;
        y = floor(i/16) * 32 + 16;
        tile.AddTile(TileData{x, y}, i);
    }
}

void Game::Draw()
{
    for(int i = 0; i < 240; i++) tile.Draw(i);
    player.Draw();
}

void Game::Update()
{
    player.Update();
}
