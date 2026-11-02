#pragma once
#include "map"
#include <vector>
#include <random>
#include "variant"
#include "BitMap.hpp"
#include <fstream>


using MapObject = std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>;
struct ObjectPosition {
    std::pair<int,int> position;
    MapObject name;
};


struct MapInformation{
    std::vector<ObjectPosition> enemies;
    std::vector<ObjectPosition> treasures;
    std::vector<ObjectPosition> player;
    Map_info map_state;
    std::vector<ObjectPosition> endstate;


};
class MapManager{
    private:
        Map_info MapBitMap;
        GameStartState game_starting_state;
        std::pair <int, int> player_starting_pos = {1,18};
        std::pair<int, int> end_state_defult = {18,1};
        int number_of_enemies = 0; //This is only if there are enemies on the loading of the board NOT if the user declares the number of enemies
        int number_of_chests = 0; //This is only if there are enemies on the loading of the board NOT if the user declares the number of enemies
        std::vector<ObjectPosition> map_read_chests;
        std::vector<ObjectPosition> map_read_enemies;
        std::vector<ObjectPosition> map_read_player;
        std::vector<ObjectPosition> map_read_end_state;

        
        //saving the final positions:
        std::vector<ObjectPosition> enemies;
        std::vector<ObjectPosition> chest;
        std::vector<ObjectPosition> player;
        std::vector<ObjectPosition> end_state;

    
    public:
        MapInformation starting_position(int &number_of_enemies, int &number_of_chests, std::string &filename);
        void build_map(std::string &filename);
        void replace_value(std::pair< int , int > &current_coords, MapObject);
        std::pair<int, int> generate_random_position();
        std::vector<ObjectPosition> generate_starting_postions(std::string name, int number);
        MapInformation reset_map(MapInformation current_map);
};
