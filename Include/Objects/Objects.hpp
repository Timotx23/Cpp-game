#pragma once
#include "raylib.h"

struct GameStartState{
    std::vector< std::pair<int, int>> player_starting_pos;
    std::vector<std::pair<int, int>> enemy_starting_pos;

};

struct Player{
    std::string sign = "P";
    int number_of_lives = 3;
    int score = 0;
    Color color = BLUE;
    std::vector<int> done_chests = {};
    
};
struct Enemy{
    std::string sign;
    Color color;
    int enemy_id;

    

};
struct Chest{
    std::string sign;
    Color color;
    int chest_id;

};
struct Wall{
    std::string sign = "#";

};
struct EmptySpace{
    std::string sign;

};

struct EndState{
    Color color = GREEN;
    std::string sign = "G";
    

};
