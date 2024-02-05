#include <iostream>
#include <raylib.h>
#include "tiles.h"
using namespace std;

#define TILE_SIZE 16

Tile::Tile()
{
    texture = LoadTexture("Images/tiles.png");
    scale = 2;
    MAP_POSITION = 0;
}

Tile::~Tile()
{
    UnloadTexture(texture);
}

void Tile::Draw(int id)
{
    DrawTexturePro(texture, spritesheet[id].source, spritesheet[id].dest, spritesheet[id].origin, 0, WHITE);
}

void Tile::Update(int id, Vector2 camera)
{
    spritesheet[id].source = Rectangle{0, 0, 16, 16};
    spritesheet[id].dest = Rectangle{data[id].x, data[id].y, spritesheet[id].source.width * scale, spritesheet[id].source.height * scale};
    spritesheet[id].origin = Vector2{spritesheet[id].dest.width / 2, spritesheet[id].dest.height / 2};

    if(camera.x - data[id].x < -336)
    {
        data[id].x -= 640;
        data[id].id_x -= 20;
    }
    if(camera.x - data[id].x > 336)
    {
        data[id].x += 640;
        data[id].id_x += 20;
    }
    if(camera.y - data[id].y < -320)
    {
        data[id].y -= 608;
        data[id].id_x -= 20;
    }
    if(camera.y - data[id].y > 320)
    {
        data[id].y += 608;
        data[id].id_y += 20;
    }
}

void Tile::AddTile(TileData data, int id)
{
    this->data[id] = data;
}

int Tile::GetTileSize()
{
   return TILE_SIZE * scale;
}
