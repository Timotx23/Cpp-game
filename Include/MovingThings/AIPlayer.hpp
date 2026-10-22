#pragma once
#include <vector>
#include <map>

class AIPlayer{
    private:
        std::map<std::string, std::pair<int,int>> movements = {{"w", {0,-1}}, {"s", {0,1}}, {"a", {-1,0}}, {"d", {1,0}}};
    public:
        std::pair<int, int> new_ai_player_pos(std::pair<int,int> player);
};