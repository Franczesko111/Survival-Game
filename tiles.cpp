#include <raylib.h>
#include "tiles.h"

#define TILE_SIZE 16

Tile::Tile()
{
    texture = LoadTexture("Images/tiles.png");
    scale = 2;
}

Tile::~Tile()
{
    UnloadTexture(texture);
}

void Tile::Draw(int id)
{
    DrawTexturePro(texture, spritesheet[id].source, spritesheet[id].dest, spritesheet[id].origin, 0, WHITE);
}

void Tile::AddTile(TileData data, int id)
{
    this->data[id] = data;

    spritesheet[id].source = Rectangle{0, 0, 16, 16};
    spritesheet[id].dest = Rectangle{data.x, data.y, spritesheet[id].source.width * scale, spritesheet[id].source.height * scale};
    spritesheet[id].origin = Vector2{spritesheet[id].dest.width / 2, spritesheet[id].dest.height / 2};
}

int Tile::GetTileSize()
{
   return TILE_SIZE * scale;
}
