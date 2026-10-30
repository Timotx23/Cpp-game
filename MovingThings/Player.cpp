#include "../Include/MovingThings/Player.hpp"

std::pair<int, int> User::get_user_input(std::pair<int,int> player_current_pos){

    
    if (IsKeyPressed(KEY_W)) {
    //move up
        player_current_pos.second-=1;
        return player_current_pos;
    }
    //move down
    else if (IsKeyPressed(KEY_S)){
        player_current_pos.second+=1;
        return player_current_pos;

    }
    //move left
    else if (IsKeyPressed(KEY_A)){
        player_current_pos.first-=1;
        return player_current_pos;

    }
    //move right 
    else if (IsKeyPressed(KEY_D)){
        player_current_pos.first+=1;
        return player_current_pos;

    }
    //dont react if its an invalid key being pressed
    else{
        return player_current_pos;
    }

};

