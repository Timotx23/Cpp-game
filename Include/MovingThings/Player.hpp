
#pragma once
#include "raylib.h"
#include <map>
#include <string>
class User{
    private:
    std::map<std::string, std::pair<int,int>> movements = {{"w", {0,-1}}, {"s", {0,1}}, {"a", {-1,0}}, {"d", {1,0}}};
    public:
        std::pair<int,int> get_user_input(std::pair<int,int> player_current_pos);


};