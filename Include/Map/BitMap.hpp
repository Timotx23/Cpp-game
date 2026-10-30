#pragma once

#include <map>
#include <utility>
#include <variant>
#include "../Objects/Objects.hpp"


struct Map_info{
        std::map<std::pair<int, int>, std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>> mazeMap = {};
std::string map_link = "";
}; 


