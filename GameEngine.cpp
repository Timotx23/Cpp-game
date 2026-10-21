/*
Manage the game states
Have the while loop that runs the game
Coordinate the states of the game

*/
#include "Include/GameEngine.hpp"
#include <iostream>


std::pair<int, int> GameEngine::new_player_pos(std::vector<ObjectPosition> player_pos){
    std::pair<int,int> player_position = player_pos[0].position;
    std::pair<int, int> new_player_pos = player.get_user_input(player_position);
    return new_player_pos;
 }

 std::vector<ObjectPosition> GameEngine::new_enemy_pos(std::vector<ObjectPosition> enemy){
    return enemy;
 }

void GameEngine::validate_chests(Map_info &map, std::map<std::pair<int,int>,std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>>::iterator& player_position,  std::vector<ObjectPosition> &chests, std::pair<int, int> &player_pos, std::vector<ObjectPosition> &player_struct){
    for (int j = 0; j < chests.size(); j ++){
            Chest& chest_data = std::get<Chest>(chests[j].name);
            //std::pair<int, int> chest_pos = chests[j].position;
            //std::cout <<"PRINT THE CHEST ID " << chest_data.chest_id <<"\n";
            //std::cout <<"PRINT THE CHEST position " << chest_pos.first << " "<< chest_pos.second <<"\n";
            if (!validate_postion(player_position->first, chests[j].position )){
                Player& p = std::get<Player>(player_struct[0].name);  
                if (std::find( p.done_chests.begin(), p.done_chests.end(),chest_data.chest_id ) == p.done_chests.end()) {
                        p.score += 10; 
                        p.done_chests.push_back(chest_data.chest_id);
                        map.mazeMap[player_pos] = p;
                        player_struct[0].position = player_pos;
                        std::cout << p.score << "\n";
                        std::cout << chest_data.chest_id << "\n";
                        std::cout << p.done_chests.size() <<"\n";
                        break;
                    }
            }        
        }
 }
 std::pair<Map_info, bool> GameEngine::update_map(Map_info map,std::vector<ObjectPosition> enemy_pos, std::pair<int, int> player_pos, std::vector<ObjectPosition> &player_struct, std::vector<ObjectPosition> &chests ){
    
    auto player_position = map.mazeMap.find(player_pos);
    if (player_position != map.mazeMap.end() && std::holds_alternative<EmptySpace>(player_position->second)){
        player_struct[0].position = player_pos;
        map.mazeMap[player_pos] =  Player{};
    }
    else if (player_position != map.mazeMap.end() && std::holds_alternative<EndState>(player_position->second)) {

    player_struct[0].position = player_pos;
    Player& p = std::get<Player>(player_struct[0].name);
    map.mazeMap[player_pos] = p;
    }
    else if (player_position != map.mazeMap.end() && std::holds_alternative<Chest>(player_position->second)){

        validate_chests(map, player_position, chests, player_pos, player_struct);
    }
    else if (player_position != map.mazeMap.end() && std::holds_alternative<Enemy>(player_position->second)){
        player_struct[0].position = player_pos;
        //map.mazeMap[player_pos] =  Enemy{};
    }
    else{
        return {map, false};
    }
    /*
    Update that the enemy only updates every 10 frames
    -> update actual enemy movements
     for (int i = 0; i < enemy_pos.size(); i ++){
        auto enemy_position = map.mazeMap.find(enemy_pos[i].position);
        if ( enemy_position != map.mazeMap.end() && std::holds_alternative<EmptySpace>(enemy_position->second)){
            map.mazeMap[enemy_pos[i].position] = Enemy{};
    }
    else{
        return {map, false};
    }
    }
    */
    return {map, true};
 }

bool GameEngine::game_state(MapInformation &start_state){
        return true;
    }
bool GameEngine::validate_postion(std::pair<int, int> player, std::pair<int,int> enemy){
    return player != enemy;
}


std::pair <MapInformation, bool> GameEngine::update_state(MapInformation &start_state){
    auto new_enemies = new_enemy_pos(start_state.enemies);
    auto old_player = start_state.player[0].position;
    auto new_player = new_player_pos(start_state.player);
    auto& chests = start_state.treasures;
    auto endstate = start_state.endstate[0];
    start_state.map_state.mazeMap[old_player] = EmptySpace{};
 
    
    std::pair<Map_info, bool> map = update_map(start_state.map_state, new_enemies, new_player, start_state.player,chests);
    if (map.second == false){
        return {start_state, true};
    }

    if (old_player != new_player) {
        if (old_player == endstate.position) {
            map.first.mazeMap[old_player] = EndState{};
        }
        else {
            map.first.mazeMap[old_player] = EmptySpace{};
        }
    }
    start_state.map_state = map.first;
    start_state.player[0].position = new_player;

    for (int i =0; i < new_enemies.size(); i ++){
        if (!validate_postion(new_player, new_enemies[i].position )){
            return {MapInformation{new_enemies, start_state.player, chests, map.first, start_state.endstate}, false};
        }
    }
    return {MapInformation{new_enemies, start_state.player, chests, map.first, start_state.endstate}, true};
}
