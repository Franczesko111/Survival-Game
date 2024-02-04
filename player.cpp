#include <raylib.h>
#include "player.h"

#define PLAYER_WIDTH 8
#define PLAYER_HEIGHT 12

Player::Player()
{
    x = GetScreenWidth() / 2 - PLAYER_WIDTH / 2;
    y = GetScreenHeight() / 2 - PLAYER_HEIGHT / 2;
    texture = LoadTexture("Images/player.png");
    speed = 3;
    scale = 3;

    animationTimer = animationFrame = 0;
}

Player::~Player()
{
    UnloadTexture(texture);
}

void Player::Draw()
{
    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}

void Player::Update()
{
    input_x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    input_y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    x += input_x * speed;
    y += input_y * speed;

    source = Rectangle{(float)animationFrame * PLAYER_WIDTH, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    dest = Rectangle{x, y, source.width * scale, source.height * scale};
    origin = Vector2{dest.width / 2, dest.height / 2};
    rotation = 0;

    if(input_x != 0 || input_y != 0){
            Animation(0.2, 1, 3);
    }else{
            animationFrame = animationTimer = 0;
    }
}

void Player::Animation(float timeleft, int startframe, int endframe)
{
    if(animationTimer == 0) animationTimer = timeleft;
    animationTimer -= GetFrameTime();
    if(animationTimer < 0)
    {
        animationTimer = timeleft;
        animationFrame++;
        if(animationFrame == endframe) animationFrame = startframe;
    }
}
