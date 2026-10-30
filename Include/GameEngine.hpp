#pragma once

#include "MovingThings/Player.hpp"
#include "MovingThings/Enemies.hpp"
#include "MovingThings/AIPlayer.hpp"
#include "Map/Map.hpp"


class GameEngine{
    private:
        User player;
        Enemy enemy;
        EnememyMovements enemy_pos;
        AIMovement ai_movement;
        double last_ai_move_time = 0.0;
        


    public:
        std::pair<int, int> new_player_pos( std::pair <int, int> player_position);
        std::pair <int, int> ai_player_pos(std::pair <int, int> player_position, Map_info &map,ObjectPosition endstate,  Player &p, std::vector<ObjectPosition> &chests);
        std::vector<ObjectPosition>  new_enemy_pos( std::vector<ObjectPosition>  enemy, Map_info &map);
        void validate_chests(Map_info &map, std::map<std::pair<int,int>,std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>>::iterator& player_position,  std::vector<ObjectPosition> &chests, std::pair<int, int> &player_pos, Player& p);// chests dont move so idk how necessary this is tbh
        bool validate_postion(std::pair<int, int> player, std::pair<int,int> enemy);
        std::pair<Map_info, bool> update_map(Map_info map,  std::vector<ObjectPosition> enemy_position,std::pair<int, int> player_pos, Player& p, std::vector<ObjectPosition> &chests);
        std::pair<MapInformation, bool> update_state(MapInformation start_state, bool is_ai);
        std::pair<std::pair<int, int>,bool>  generate_player(std::pair<int, int>player_position , bool is_ai, MapInformation &current_state, ObjectPosition endstate, Player &p, std::vector<ObjectPosition> &chests);
        
      

};
