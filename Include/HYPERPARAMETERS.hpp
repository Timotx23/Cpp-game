#pragma once
#include "string"

struct HyperParameters{
    std::string FILENAME = "Map/Map.txt";
    int CHESTS = 5;
    int ENEMIES = 3;
    int GRIDSIZE_X = 20;
    int GRIDSIZE_Y = 20;
    bool is_test_mode = true;
    int is_ai_player = 9;

};