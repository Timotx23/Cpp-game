#include "../Include/Map/Map.hpp"
#include <random>
#include <iostream>
/*
Responsibilities:
    - Load the inital state
    - Load enemies in random positions on the map
    - keep track of character postions 


*/

MapInformation MapManager::starting_position(int number_of_enemies, int number_of_chests){
    /*
    Set the starting positions
    Load the map and make sure
    */
    std::vector<ObjectPosition> enemies = generate_starting_postions("enemy", number_of_enemies);
    std::vector<ObjectPosition> chest = generate_starting_postions("chest", number_of_chests);
    std::vector<ObjectPosition> player = generate_starting_postions("player", 1);
    std::vector<ObjectPosition> end_state = generate_starting_postions("end_state", 1);
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
            
            coords = {1,18}; // only hard coded coord
         
            pos.push_back(ObjectPosition{coords, Player{}});
        }
        
        else if(name == "end_state"){
            coords = {18,1}; // only hard coded coord
            replace_value(coords, EndState{} );
            pos.push_back(ObjectPosition{coords, EndState{} });

        }
        

        else{
            coords = generate_random_position();
            if (name == "chest"){
                Chest chest{"C", YELLOW, i}; 
                replace_value(coords, chest );
                pos.push_back(ObjectPosition{coords, chest });
            }
            else{
                Enemy enemy{"E", RED, i};
                replace_value(coords, enemy );
                pos.push_back(ObjectPosition{coords, enemy });
            }
        }

    }
    return pos;
};




