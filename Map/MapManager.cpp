#include "../Include/Map/Map.hpp"
#include <random>
#include <iostream>
/*
Responsibilities:
    - Load the inital state
    - Load enemies in random positions on the map
    - keep track of character postions 



*/


void  MapManager::build_map(std::string &filename){
    std::ifstream file(filename);
    std::string line;
    int y_coords = 0;    
    if(!file.is_open()){
        throw std::invalid_argument("Invalid file format");
    }
    while (std::getline(file, line)) {
        for (int i = 0; i < line.length(); i++){
            std::pair<int, int> coords = {i, y_coords};
            if (line[i] == '#'){
                MapBitMap.mazeMap[{i, y_coords}] = Wall{};
            }
            else if (line[i] == '.'){
                MapBitMap.mazeMap[{i, y_coords}] = EmptySpace{};

            }
            else if(line[i] == 'P'){
                MapBitMap.mazeMap[{i, y_coords}] = Player{};
                MapBitMap.contains_objects["Player"] = true;
                
                map_read_player.push_back(ObjectPosition{coords, Player{} });

            }
            else if (line[i] == 'X'){
                MapBitMap.mazeMap[{i, y_coords}] = EndState{};
                MapBitMap.contains_objects["Exit"] = true;
                map_read_end_state.push_back(ObjectPosition{coords, EndState{} });
            }
            else if (line[i] == 'E'){
                Enemy enemy{"E", RED, number_of_enemies};
                number_of_enemies+=1;
                
                MapBitMap.mazeMap[coords] = enemy;
                MapBitMap.contains_objects["Enemy"] = true;
                map_read_enemies.push_back(ObjectPosition{coords, enemy });

            }
            else if (line[i] == 'T'){
                Chest chest{"C", YELLOW, number_of_chests};
                number_of_chests+=1;
                MapBitMap.mazeMap[coords] = chest;
                map_read_chests.push_back(ObjectPosition{coords, chest });
                MapBitMap.contains_objects["Treasure"] = true;
            }
            else{
                throw std::invalid_argument("Invalid character '" + std::string(1, line[i]) + "' at x=" + std::to_string(i) + ", y=" + std::to_string(y_coords));
            }       
        }
        y_coords +=1;
}
MapBitMap.map_link = filename;
file.close();



    
};
MapInformation MapManager::starting_position(int &number_of_enemies, int &number_of_chests, std::string &filename){
    /*
    Set the starting positions
    Load the map and make sure

    */
   try{
    build_map(filename);
   }
   
    catch (const std::exception& e) {
        std::cerr << "Map loading failed: " << e.what() << std::endl;
    }
    
    for (const auto& item :MapBitMap.contains_objects ) {

        if (item.first == "Player"){
            if(item.second == false){
                player = generate_starting_postions("player", 1);
            }
            else{
                player = map_read_player;
            }
        }
        else if (item.first == "Treasure"){
            if (item.second == false){
                chest = generate_starting_postions("chest", number_of_chests);
            }
            else{
                chest = map_read_chests;
        }
    }
        else if (item.first == "Enemy"){
          if (  item.second == false){
           enemies = generate_starting_postions("enemy", number_of_enemies);
          }
          else{
            enemies = map_read_enemies;
          }
        } 
        else if (item.first == "Exit"){
            if (item.second == false){
                end_state = generate_starting_postions("end_state", 1);
            }
            else{
                end_state = map_read_end_state;
            }
        }
        }

    /*
    std::vector<ObjectPosition> enemies = generate_starting_postions("enemy", number_of_enemies);
    std::vector<ObjectPosition> chest = generate_starting_postions("chest", number_of_chests);
    std::vector<ObjectPosition> player = generate_starting_postions("player", 1);
    std::vector<ObjectPosition> end_state = generate_starting_postions("end_state", 1);
    */
    
    return MapInformation{enemies,chest,player,MapBitMap, end_state};
};

void MapManager::replace_value(std::pair< int , int > &current_coords,  MapObject map_object){
   
    MapBitMap.mazeMap.at(current_coords) = map_object;
   
}


std::pair<int, int> MapManager::generate_random_position() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 18);

    while (true) {
        std::pair<int, int> coords = {distribution(generator),distribution(generator)};

        if (std::holds_alternative<EmptySpace>(MapBitMap.mazeMap.at(coords))) {
            return coords;
        }
    }
}

std::vector<ObjectPosition> MapManager::generate_starting_postions(std::string name, int number){
    std::vector<ObjectPosition> pos = {};
    for (int i = 0; i < number; i ++){
        std::pair<int, int> coords = {0,0};
        if (name == "player"){
            coords = player_starting_pos;
            replace_value(coords, Player{}); // Place player on map
            pos.push_back(ObjectPosition{coords, Player{}});
            game_starting_state.player_starting_pos.push_back(coords);
        }
        
        else if(name == "end_state"){
            coords = end_state_defult; 
            replace_value(coords, EndState{} );
            pos.push_back(ObjectPosition{coords, EndState{} });

        }
        
        else{
            coords = generate_random_position();
            if (name == "chest"){
                Chest chest{"T", YELLOW, i}; 
                replace_value(coords, chest );
                pos.push_back(ObjectPosition{coords, chest });
            }
            else{
                Enemy enemy{"E", RED, i};
                replace_value(coords, enemy );
                game_starting_state.enemy_starting_pos.push_back(coords);
                pos.push_back(ObjectPosition{coords, enemy });
            }
        }

    }
    return pos;
};

MapInformation MapManager::reset_map(MapInformation current_state) {

    //Remove all enemies from the field before doing anything else -> this fixes the duplication issue
    for (auto& [coords, tile] : current_state.map_state.mazeMap) {
        if (std::holds_alternative<Enemy>(tile)) {
            tile = EmptySpace{};
        }
    }
    //reset player and make sure they start in the original position
    std::pair<int, int> old_player_pos = current_state.player[0].position;
    current_state.map_state.mazeMap.at(old_player_pos) = EmptySpace{};
    current_state.player[0].position =game_starting_state.player_starting_pos[0];
    Player& p = std::get<Player>(current_state.player[0].name);
    current_state.map_state.mazeMap.at(game_starting_state.player_starting_pos[0]) = p;

    // reset each individual enemy that is on the field
    for (size_t i = 0; i < current_state.enemies.size(); i++) {
        std::pair<int, int> starting_pos = game_starting_state.enemy_starting_pos[i];
        current_state.enemies[i].position = starting_pos;
        Enemy& enemy = std::get<Enemy>(current_state.enemies[i].name);
        current_state.map_state.mazeMap.at(starting_pos) = enemy;
    }
    return current_state;
}



