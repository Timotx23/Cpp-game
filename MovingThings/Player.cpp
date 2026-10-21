#include "../Include/MovingThings/Player.hpp"

std::pair<int, int> User::get_user_input(std::pair<int,int> player_current_pos){

    //std::map<std::string, std::pair<int,int>> movements = {{"w", {0,-1}}, {"s", {0,1}}, {"a", {-1,0}}, {"d", {1,0}}};
    if (IsKeyPressed(KEY_W)) {
    // move up
        player_current_pos.second-=1;
        return player_current_pos;
    }
    else if (IsKeyPressed(KEY_S)){
        player_current_pos.second+=1;
        return player_current_pos;

    }
    else if (IsKeyPressed(KEY_A)){
        player_current_pos.first-=1;
        return player_current_pos;

    }
    else if (IsKeyPressed(KEY_D)){
        player_current_pos.first+=1;
        return player_current_pos;

    }
    else{
        return player_current_pos;
    }

};

