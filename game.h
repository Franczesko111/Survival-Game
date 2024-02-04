#pragma once
#include <raylib.h>
#include "player.h"
#include "tiles.h"

class Game
{
    public:
        Game();
        void Draw();
        void Update();

    private:
        Player player;
        Tile tile;
        Camera2D camera;
};
