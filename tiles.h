#pragma once
#include <raylib.h>

class Tiles
{
    public:
        Tiles();
        ~Tiles();
        void Draw();
        void AddTile(float x, float y);

    private:
        Texture2D texture;
        Rectangle source;
        Rectangle dest;
        Vector2 origin;
        float x, y, rotation;
        int scale;
};
