#include <raylib.h>
#include "player.h"

Player::Player()
{
    width = 24;
    height = 36;
    x = GetScreenWidth() / 2 - width / 2;
    y = GetScreenHeight() / 2 - height / 2;
    speed = 3;
}

Player::~Player()
{

}

void Player::Draw()
{
    DrawRectangle(x, y, width, height, RED);
}

void Player::Update()
{
    x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * speed;
    y += (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * speed;
}
