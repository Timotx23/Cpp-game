#pragma once

#include "MovingThings/Player.hpp"
#include "MovingThings/Enemies.hpp"
#include "Map/Map.hpp"


class GameEngine{
    private:
        User player;
        Enemy enemy;

    public:
        std::pair<int, int> new_player_pos( std::vector<ObjectPosition> player);
        std::vector<ObjectPosition> new_enemy_pos(std::vector<ObjectPosition> enemy);
        void validate_chests(Map_info &map, std::map<std::pair<int,int>,std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>>::iterator& player_position,  std::vector<ObjectPosition> &chests, std::pair<int, int> &player_pos, std::vector<ObjectPosition> &player_struct);// chests dont move so idk how necessary this is tbh
        bool validate_postion(std::pair<int, int> player, std::pair<int,int> enemy);
        std::pair<Map_info, bool> update_map(Map_info map,  std::vector<ObjectPosition> enemy_position,std::pair<int, int> player_pos, std::vector<ObjectPosition> &player, std::vector<ObjectPosition> &chests);
        bool game_state(MapInformation &start_state);
        std::pair<int, int> valid_player_move(std::vector<ObjectPosition> player_pos);
        std::pair<MapInformation, bool> update_state(MapInformation start_state);
        bool game_finished();


    /*
    check the player pos
    check the enemy pos
    check how many chests player has taken
    
    
    
    */

};
