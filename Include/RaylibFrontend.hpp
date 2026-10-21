#pragma once

#include "raylib.h"
#include "Map/Map.hpp"

class RaylibFrontend {
public:
    RaylibFrontend(int tileSize = 32);
    void run(MapInformation& mapInfo);
    int tileSize;
    void drawMap(MapInformation& mapInfo);
};
