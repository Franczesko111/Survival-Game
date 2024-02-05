#pragma once
#include <raylib.h>

typedef struct TileData
{
    float x;
    float y;
    int id_x;
    int id_y;
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
        void Update(int id, Vector2 camera);
        void AddTile(TileData data, int id);
        int GetTileSize();

    private:
        int MAP_POSITION, scale;
        Texture2D texture;
        TileData data[380];
        Spritesheet spritesheet[380];
};
