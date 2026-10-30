#pragma once
#include <vector>
#include <map>
#include "../Map/Map.hpp"

struct Node{
    std::pair<int,int> position;
        int g_cost;
        int h_cost;
        int f_cost;
    };



struct AIPlayer{
    std::vector<Node> open_list;
    std::vector<Node> closed_lst;
    int current_cost;


};
class AIMovement{
    private:
        
        Node node;
        AIPlayer ai_player;
        std::vector<std::pair<int,int>> movements = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    public:
        
        std::pair<int, int> new_ai_player_pos(std::pair <int, int> ai_player_position, Map_info &map,std::pair<int, int> goal_pos, int current_cost);

};