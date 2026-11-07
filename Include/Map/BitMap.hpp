#pragma once

#include <map>
#include <utility>
#include <variant>
#include "../Objects/Objects.hpp"


struct Map_info{
        std::map<std::pair<int, int>, std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>> mazeMap = {};
std::string map_link = "";
std::map<std::string, bool> contains_objects = {{"Player", false}, {"Enemy", false}, {"Treasure", false}, {"Exit", false} }; //Bug if there are 3 different treasures and user only provides 1 then the system will only load 1

}; 


