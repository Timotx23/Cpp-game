/*
Manage the game states
Have the while loop that runs the game
Coordinate the states of the game

*/
#include "Include/GameEngine.hpp"
#include <iostream>
#include <raylib.h>


std::pair<int, int> GameEngine::new_player_pos(std::pair <int, int> player_position){
    std::pair<int, int> new_player_pos = player.get_user_input(player_position);
    return new_player_pos;
 }
 std::pair <int, int> GameEngine::ai_player_pos(std::pair <int, int> ai_player_position, Map_info &map, ObjectPosition endstate, Player &p, std::vector<ObjectPosition> &chests ){
    /*
        check if chests are remaining
        if yes:
        -   check which chest is closest to player
            - move to that chest
        else:
            move to endstate

        It needs to get to the same chest till it gets to that chest 
    */
    
    if (p.done_chests.size() != chests.size()){
        if (!(p.goal_chest_coords.first == 20 && p.goal_chest_coords.second == 20)){
            auto next_move =  ai_movement.new_ai_player_pos(ai_player_position, map,  p.goal_chest_coords, p.current_cost);
            return next_move;
        }
        std::pair<int, int> shortest_chest_coord = {20,20};
        int min_distance = 1000;
        for (int i = 0; i < chests.size(); i ++){
            Chest& chest_data = std::get<Chest>(chests[i].name);
            if (std::find( p.done_chests.begin(), p.done_chests.end(),chest_data.chest_id ) == p.done_chests.end()){
                int tot_cost = std::abs(chests[i].position.first - ai_player_position.first) +  std::abs(chests[i].position.second - ai_player_position.second);
                if (tot_cost < min_distance){
                    min_distance = tot_cost;
                    shortest_chest_coord = chests[i].position;
                }
            }
        }

        p.goal_chest_coords = shortest_chest_coord;
        std::cout << "IS it getting here? " <<"\n";
        return ai_movement.new_ai_player_pos(ai_player_position, map, p.goal_chest_coords, p.current_cost);
   }
   else{
        return ai_movement.new_ai_player_pos(ai_player_position, map, endstate.position, p.current_cost );
   }
 }
 std::vector<ObjectPosition> GameEngine::new_enemy_pos(std::vector<ObjectPosition> enemy, Map_info &map){
    //Update such that it also takes in the position of the player and optimizes towards that
    for (int i = 0; i < enemy.size(); i++){
        Enemy& e = std::get<Enemy>(enemy[i].name);
        ObjectPosition current_enemy_pos = enemy[i];
        std::pair<int, int> new_enemy_pos = enemy_pos.calculate_enemy_movement(current_enemy_pos.position);
        auto map_enemy_position = map.mazeMap.find(new_enemy_pos);
        if (map_enemy_position != map.mazeMap.end() && std::holds_alternative<EmptySpace>(map_enemy_position->second)){
            map.mazeMap[current_enemy_pos.position] = EmptySpace{};
            enemy[i].position = new_enemy_pos;
            map.mazeMap[new_enemy_pos] = e;
            }
    }
    return enemy;
 }


void GameEngine::validate_chests(Map_info &map, std::map<std::pair<int,int>,std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>>::iterator& player_position,  std::vector<ObjectPosition> &chests, std::pair<int, int> &player_pos, Player& p){
    for (int j = 0; j < chests.size(); j ++){
            Chest& chest_data = std::get<Chest>(chests[j].name);
            if (!validate_postion(player_position->first, chests[j].position )){ 
                if (std::find( p.done_chests.begin(), p.done_chests.end(),chest_data.chest_id ) == p.done_chests.end()) {
                        p.score += 10; 
                        p.done_chests.push_back(chest_data.chest_id);
                        p.goal_chest_coords = {20,20};
                        map.mazeMap[player_pos] = p;
                        break;
                    }
            }        
        }
 }
 std::pair<Map_info, bool> GameEngine::update_map(Map_info map,std::vector<ObjectPosition> enemy_pos, std::pair<int, int> player_pos, Player& p , std::vector<ObjectPosition> &chests ){
    
    auto player_position = map.mazeMap.find(player_pos);
    if (player_position == map.mazeMap.end()) {
        return {map, false};
    }
    else if (player_position != map.mazeMap.end()){
        if ((std::holds_alternative<EmptySpace>(player_position->second)) || (std::holds_alternative<EndState>(player_position->second)) || (std::holds_alternative<Enemy>(player_position->second)) ){
            map.mazeMap[player_pos] = p;
            return {map, true};
        }
        else if (std::holds_alternative<Chest>(player_position->second)){
            validate_chests(map, player_position, chests, player_pos, p);
            return {map, true};
        } 
    }
        return {map, false};
    

 }

bool GameEngine::validate_postion(std::pair<int, int> player, std::pair<int,int> enemy){
    return player != enemy;
}

std::pair<std::pair<int, int>,bool> GameEngine::generate_player(std::pair<int, int>player_position , bool is_ai, MapInformation &current_state, ObjectPosition endstate, Player &p, std::vector<ObjectPosition> &chests){
    if (!is_ai){
        return {new_player_pos(player_position), true};
    }
    
        double current_time = GetTime();
        if (current_time - last_ai_move_time < 0.5) {
        return {player_position, false};
        }
        std::pair<int, int> new_player = ai_player_pos(player_position, current_state.map_state, endstate, p, chests );
        last_ai_move_time = current_time;
        return {new_player, true};
}



std::pair <MapInformation, bool> GameEngine::update_state(MapInformation current_state, bool is_ai){
    /*
    This is the logic handler of each state of the game
    - Get the old position of player
    - Get the actual player struct from the current state
    */
    auto old_player = current_state.player[0].position;
    Player& p = std::get<Player>(current_state.player[0].name);

    std::pair<int,int> player_position = old_player;
    std::pair<int,int>  new_player = {0,0};
    auto& chests = current_state.treasures;
    auto endstate = current_state.endstate[0];

    std::pair<std::pair<int, int>,bool> temp_player = generate_player(player_position, is_ai, current_state, endstate, p, chests);
    if (!temp_player.second){
        return {current_state, true};
    }
        new_player = temp_player.first;
    if (old_player == new_player) {
            return {current_state, true};
        }
    auto new_enemies = new_enemy_pos(current_state.enemies, current_state.map_state);
    for (int i =0; i < new_enemies.size(); i ++){
        if (!validate_postion(new_player, new_enemies[i].position )){
            return {current_state, false};
        }
    }
    current_state.enemies = new_enemies;
    std::pair<Map_info, bool> map = update_map(current_state.map_state, new_enemies, new_player, p,chests);
    if (map.second == false){
        return {current_state, true};
    }
    if (old_player == endstate.position) {
        map.first.mazeMap[old_player] = EndState{};
    }
    else {
        map.first.mazeMap[old_player] = EmptySpace{};
    }
    
    
    current_state.player[0].position = new_player;
    current_state.map_state = map.first;
    current_state.treasures = chests;

    
    return {current_state, true};
}
