#include <raylib.h>
#include "tiles.h"

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

Tiles::Tiles()
{
    texture = LoadTexture("Images/tiles.png");
    scale = 2;
}

Tiles::~Tiles()
{
    UnloadTexture(texture);
}

void Tiles::Draw()
{
    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}

void Tiles::AddTile(float x, float y)
{
    this->x = x;
    this->y = y;

    source = Rectangle{0, 0, TILE_WIDTH, TILE_HEIGHT};
    dest = Rectangle{x, y, source.width * scale, source.height * scale};
    origin = Vector2{dest.width / 2, dest.height / 2};
    rotation = 0;
}
