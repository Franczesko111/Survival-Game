#pragma once
#include <raylib.h>

typedef struct TileData
{
    float x;
    float y;
} TileData;

typedef struct Spritesheet
{
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
} Spritesheet;

class Tile
{
    public:
        Tile();
        ~Tile();
        void Draw(int id);
        void AddTile(TileData data, int id);
        int GetTileSize();

    private:
        int scale;
        Texture2D texture;
        TileData data[240];
        Spritesheet spritesheet[240];
};
