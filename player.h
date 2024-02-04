#pragma once
#include <raylib.h>

class Player
{
    public:
        Player();
        ~Player();
        void Draw();
        void Update();

    private:
        Texture2D texture;
        Rectangle source;
        Rectangle dest;
        Vector2 origin;
        float x, y, rotation, animationTimer;
        int speed, scale, input_x, input_y, animationFrame;

        void Animation(float timeleft, int startframe, int endframe);
};
