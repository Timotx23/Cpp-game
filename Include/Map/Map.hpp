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
    public:
        MapInformation starting_position(int &number_of_enemies, int &number_of_chests, std::string &filename);
        void build_map(std::string &filename);
        void replace_value(std::pair< int , int > &current_coords, MapObject);
        std::pair<int, int> generate_random_position();
        std::vector<ObjectPosition> generate_starting_postions(std::string name, int number);
        MapInformation reset_map(MapInformation current_map);
};
