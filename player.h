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
        float x, y, width, height;
        int speed;
};
