#include <raylib.h>
#include "game.h"

Game::Game()
{
    for(int i = 0; i < 240; i++) tiles[i].AddTile(i%16 * 32 + 16, i/16 * 32 + 16);
}

void Game::Draw()
{
    for(int i = 0; i < 240; i++) tiles[i].Draw();
    player.Draw();
}

void Game::Update()
{
    player.Update();
}
