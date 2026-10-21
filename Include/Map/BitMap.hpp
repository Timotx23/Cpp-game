#pragma once

#include <map>
#include <utility>
#include <variant>
#include "../Objects/Objects.hpp"


struct Map_info{
        std::map<std::pair<int, int>, std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>> mazeMap = {
    {{0,0}, Wall{}}, {{1,0}, Wall{}}, {{2,0}, Wall{}}, {{3,0}, Wall{}}, {{4,0}, Wall{}}, {{5,0}, Wall{}}, {{6,0}, Wall{}}, {{7,0}, Wall{}}, {{8,0}, Wall{}}, {{9,0}, Wall{}}, {{10,0}, Wall{}}, {{11,0}, Wall{}}, {{12,0}, Wall{}}, {{13,0}, Wall{}}, {{14,0}, Wall{}}, {{15,0}, Wall{}}, {{16,0}, Wall{}}, {{17,0}, Wall{}}, {{18,0}, Wall{}}, {{19,0}, Wall{}},

    {{0,1}, Wall{}}, {{1,1}, EmptySpace{}}, {{2,1}, EmptySpace{}}, {{3,1}, EmptySpace{}}, {{4,1}, EmptySpace{}}, {{5,1}, EmptySpace{}}, {{6,1}, EmptySpace{}}, {{7,1}, EmptySpace{}}, {{8,1}, EmptySpace{}}, {{9,1}, EmptySpace{}}, {{10,1}, EmptySpace{}}, {{11,1}, EmptySpace{}}, {{12,1}, EmptySpace{}}, {{13,1}, EmptySpace{}}, {{14,1}, EmptySpace{}}, {{15,1}, EmptySpace{}}, {{16,1}, EmptySpace{}}, {{17,1}, EmptySpace{}}, {{18,1}, EmptySpace{}}, {{19,1}, Wall{}},

    {{0,2}, Wall{}}, {{1,2}, EmptySpace{}}, {{2,2}, EmptySpace{}}, {{3,2}, EmptySpace{}}, {{4,2}, EmptySpace{}}, {{5,2}, EmptySpace{}}, {{6,2}, Wall{}}, {{7,2}, Wall{}}, {{8,2}, EmptySpace{}}, {{9,2}, Wall{}}, {{10,2}, EmptySpace{}}, {{11,2}, EmptySpace{}}, {{12,2}, Wall{}}, {{13,2}, EmptySpace{}}, {{14,2}, Wall{}}, {{15,2}, EmptySpace{}}, {{16,2}, EmptySpace{}}, {{17,2}, EmptySpace{}}, {{18,2}, EmptySpace{}}, {{19,2}, Wall{}},

    {{0,3}, Wall{}}, {{1,3}, EmptySpace{}}, {{2,3}, EmptySpace{}}, {{3,3}, EmptySpace{}}, {{4,3}, Wall{}}, {{5,3}, Wall{}}, {{6,3}, Wall{}}, {{7,3}, EmptySpace{}}, {{8,3}, EmptySpace{}}, {{9,3}, EmptySpace{}}, {{10,3}, Wall{}}, {{11,3}, EmptySpace{}}, {{12,3}, EmptySpace{}}, {{13,3}, Wall{}}, {{14,3}, EmptySpace{}}, {{15,3}, EmptySpace{}}, {{16,3}, EmptySpace{}}, {{17,3}, EmptySpace{}}, {{18,3}, Wall{}}, {{19,3}, Wall{}},

    {{0,4}, Wall{}}, {{1,4}, EmptySpace{}}, {{2,4}, EmptySpace{}}, {{3,4}, EmptySpace{}}, {{4,4}, EmptySpace{}}, {{5,4}, EmptySpace{}}, {{6,4}, EmptySpace{}}, {{7,4}, EmptySpace{}}, {{8,4}, EmptySpace{}}, {{9,4}, EmptySpace{}}, {{10,4}, EmptySpace{}}, {{11,4}, Wall{}}, {{12,4}, EmptySpace{}}, {{13,4}, EmptySpace{}}, {{14,4}, EmptySpace{}}, {{15,4}, EmptySpace{}}, {{16,4}, EmptySpace{}}, {{17,4}, Wall{}}, {{18,4}, Wall{}}, {{19,4}, Wall{}},

    {{0,5}, Wall{}}, {{1,5}, EmptySpace{}}, {{2,5}, Wall{}}, {{3,5}, EmptySpace{}}, {{4,5}, EmptySpace{}}, {{5,5}, Wall{}}, {{6,5}, EmptySpace{}}, {{7,5}, EmptySpace{}}, {{8,5}, EmptySpace{}}, {{9,5}, EmptySpace{}}, {{10,5}, EmptySpace{}}, {{11,5}, EmptySpace{}}, {{12,5}, EmptySpace{}}, {{13,5}, EmptySpace{}}, {{14,5}, EmptySpace{}}, {{15,5}, EmptySpace{}}, {{16,5}, EmptySpace{}}, {{17,5}, EmptySpace{}}, {{18,5}, Wall{}}, {{19,5}, Wall{}},

    {{0,6}, Wall{}}, {{1,6}, EmptySpace{}}, {{2,6}, EmptySpace{}}, {{3,6}, EmptySpace{}}, {{4,6}, Wall{}}, {{5,6}, EmptySpace{}}, {{6,6}, Wall{}}, {{7,6}, EmptySpace{}}, {{8,6}, Wall{}}, {{9,6}, EmptySpace{}}, {{10,6}, EmptySpace{}}, {{11,6}, EmptySpace{}}, {{12,6}, Wall{}}, {{13,6}, EmptySpace{}}, {{14,6}, EmptySpace{}}, {{15,6}, EmptySpace{}}, {{16,6}, EmptySpace{}}, {{17,6}, EmptySpace{}}, {{18,6}, Wall{}}, {{19,6}, Wall{}},

    {{0,7}, Wall{}}, {{1,7}, EmptySpace{}}, {{2,7}, EmptySpace{}}, {{3,7}, EmptySpace{}}, {{4,7}, EmptySpace{}}, {{5,7}, EmptySpace{}}, {{6,7}, EmptySpace{}}, {{7,7}, EmptySpace{}}, {{8,7}, EmptySpace{}}, {{9,7}, EmptySpace{}}, {{10,7}, Wall{}}, {{11,7}, EmptySpace{}}, {{12,7}, EmptySpace{}}, {{13,7}, EmptySpace{}}, {{14,7}, EmptySpace{}}, {{15,7}, Wall{}}, {{16,7}, EmptySpace{}}, {{17,7}, EmptySpace{}}, {{18,7}, EmptySpace{}}, {{19,7}, Wall{}},

    {{0,8}, Wall{}}, {{1,8}, EmptySpace{}}, {{2,8}, EmptySpace{}}, {{3,8}, EmptySpace{}}, {{4,8}, EmptySpace{}}, {{5,8}, EmptySpace{}}, {{6,8}, EmptySpace{}}, {{7,8}, EmptySpace{}}, {{8,8}, Wall{}}, {{9,8}, EmptySpace{}}, {{10,8}, EmptySpace{}}, {{11,8}, EmptySpace{}}, {{12,8}, EmptySpace{}}, {{13,8}, Wall{}}, {{14,8}, EmptySpace{}}, {{15,8}, EmptySpace{}}, {{16,8}, Wall{}}, {{17,8}, EmptySpace{}}, {{18,8}, Wall{}}, {{19,8}, Wall{}},

    {{0,9}, Wall{}}, {{1,9}, EmptySpace{}}, {{2,9}, EmptySpace{}}, {{3,9}, EmptySpace{}}, {{4,9}, EmptySpace{}}, {{5,9}, EmptySpace{}}, {{6,9}, EmptySpace{}}, {{7,9}, EmptySpace{}}, {{8,9}, EmptySpace{}}, {{9,9}, EmptySpace{}}, {{10,9}, EmptySpace{}}, {{11,9}, EmptySpace{}}, {{12,9}, EmptySpace{}}, {{13,9}, EmptySpace{}}, {{14,9}, EmptySpace{}}, {{15,9}, EmptySpace{}}, {{16,9}, EmptySpace{}}, {{17,9}, Wall{}}, {{18,9}, EmptySpace{}}, {{19,9}, Wall{}},

    {{0,10}, Wall{}}, {{1,10}, Wall{}}, {{2,10}, EmptySpace{}}, {{3,10}, EmptySpace{}}, {{4,10}, EmptySpace{}}, {{5,10}, EmptySpace{}}, {{6,10}, EmptySpace{}}, {{7,10}, Wall{}}, {{8,10}, EmptySpace{}}, {{9,10}, EmptySpace{}}, {{10,10}, EmptySpace{}}, {{11,10}, EmptySpace{}}, {{12,10}, Wall{}}, {{13,10}, EmptySpace{}}, {{14,10}, Wall{}}, {{15,10}, EmptySpace{}}, {{16,10}, EmptySpace{}}, {{17,10}, Wall{}}, {{18,10}, EmptySpace{}}, {{19,10}, Wall{}},

    {{0,11}, Wall{}}, {{1,11}, EmptySpace{}}, {{2,11}, EmptySpace{}}, {{3,11}, Wall{}}, {{4,11}, EmptySpace{}}, {{5,11}, Wall{}}, {{6,11}, EmptySpace{}}, {{7,11}, EmptySpace{}}, {{8,11}, Wall{}}, {{9,11}, EmptySpace{}}, {{10,11}, EmptySpace{}}, {{11,11}, Wall{}}, {{12,11}, EmptySpace{}}, {{13,11}, Wall{}}, {{14,11}, EmptySpace{}}, {{15,11}, EmptySpace{}}, {{16,11}, EmptySpace{}}, {{17,11}, EmptySpace{}}, {{18,11}, EmptySpace{}}, {{19,11}, Wall{}},

    {{0,12}, Wall{}}, {{1,12}, EmptySpace{}}, {{2,12}, EmptySpace{}}, {{3,12}, EmptySpace{}}, {{4,12}, EmptySpace{}}, {{5,12}, EmptySpace{}}, {{6,12}, EmptySpace{}}, {{7,12}, EmptySpace{}}, {{8,12}, EmptySpace{}}, {{9,12}, EmptySpace{}}, {{10,12}, EmptySpace{}}, {{11,12}, Wall{}}, {{12,12}, Wall{}}, {{13,12}, EmptySpace{}}, {{14,12}, EmptySpace{}}, {{15,12}, EmptySpace{}}, {{16,12}, EmptySpace{}}, {{17,12}, EmptySpace{}}, {{18,12}, EmptySpace{}}, {{19,12}, Wall{}},

    {{0,13}, Wall{}}, {{1,13}, EmptySpace{}}, {{2,13}, EmptySpace{}}, {{3,13}, Wall{}}, {{4,13}, EmptySpace{}}, {{5,13}, EmptySpace{}}, {{6,13}, EmptySpace{}}, {{7,13}, Wall{}}, {{8,13}, EmptySpace{}}, {{9,13}, EmptySpace{}}, {{10,13}, EmptySpace{}}, {{11,13}, Wall{}}, {{12,13}, EmptySpace{}}, {{13,13}, Wall{}}, {{14,13}, EmptySpace{}}, {{15,13}, EmptySpace{}}, {{16,13}, Wall{}}, {{17,13}, EmptySpace{}}, {{18,13}, Wall{}}, {{19,13}, Wall{}},

    {{0,14}, Wall{}}, {{1,14}, EmptySpace{}}, {{2,14}, EmptySpace{}}, {{3,14}, EmptySpace{}}, {{4,14}, EmptySpace{}}, {{5,14}, EmptySpace{}}, {{6,14}, EmptySpace{}}, {{7,14}, Wall{}}, {{8,14}, EmptySpace{}}, {{9,14}, EmptySpace{}}, {{10,14}, EmptySpace{}}, {{11,14}, EmptySpace{}}, {{12,14}, EmptySpace{}}, {{13,14}, EmptySpace{}}, {{14,14}, EmptySpace{}}, {{15,14}, EmptySpace{}}, {{16,14}, EmptySpace{}}, {{17,14}, EmptySpace{}}, {{18,14}, EmptySpace{}}, {{19,14}, Wall{}},

    {{0,15}, Wall{}}, {{1,15}, EmptySpace{}}, {{2,15}, EmptySpace{}}, {{3,15}, EmptySpace{}}, {{4,15}, EmptySpace{}}, {{5,15}, EmptySpace{}}, {{6,15}, EmptySpace{}}, {{7,15}, EmptySpace{}}, {{8,15}, Wall{}}, {{9,15}, EmptySpace{}}, {{10,15}, Wall{}}, {{11,15}, EmptySpace{}}, {{12,15}, EmptySpace{}}, {{13,15}, EmptySpace{}}, {{14,15}, EmptySpace{}}, {{15,15}, Wall{}}, {{16,15}, EmptySpace{}}, {{17,15}, Wall{}}, {{18,15}, Wall{}}, {{19,15}, Wall{}},

    {{0,16}, Wall{}}, {{1,16}, EmptySpace{}}, {{2,16}, EmptySpace{}}, {{3,16}, EmptySpace{}}, {{4,16}, EmptySpace{}}, {{5,16}, EmptySpace{}}, {{6,16}, EmptySpace{}}, {{7,16}, EmptySpace{}}, {{8,16}, EmptySpace{}}, {{9,16}, Wall{}}, {{10,16}, EmptySpace{}}, {{11,16}, EmptySpace{}}, {{12,16}, EmptySpace{}}, {{13,16}, Wall{}}, {{14,16}, EmptySpace{}}, {{15,16}, EmptySpace{}}, {{16,16}, EmptySpace{}}, {{17,16}, EmptySpace{}}, {{18,16}, Wall{}}, {{19,16}, Wall{}},

    {{0,17}, Wall{}}, {{1,17}, EmptySpace{}}, {{2,17}, Wall{}}, {{3,17}, EmptySpace{}}, {{4,17}, EmptySpace{}}, {{5,17}, EmptySpace{}}, {{6,17}, EmptySpace{}}, {{7,17}, EmptySpace{}}, {{8,17}, EmptySpace{}}, {{9,17}, EmptySpace{}}, {{10,17}, Wall{}}, {{11,17}, EmptySpace{}}, {{12,17}, EmptySpace{}}, {{13,17}, EmptySpace{}}, {{14,17}, EmptySpace{}}, {{15,17}, EmptySpace{}}, {{16,17}, EmptySpace{}}, {{17,17}, EmptySpace{}}, {{18,17}, Wall{}}, {{19,17}, Wall{}},

    {{0,18}, Wall{}}, {{1,18}, EmptySpace{}}, {{2,18}, EmptySpace{}}, {{3,18}, EmptySpace{}}, {{4,18}, EmptySpace{}}, {{5,18}, EmptySpace{}}, {{6,18}, EmptySpace{}}, {{7,18}, EmptySpace{}}, {{8,18}, EmptySpace{}}, {{9,18}, EmptySpace{}}, {{10,18}, EmptySpace{}}, {{11,18}, EmptySpace{}}, {{12,18}, Wall{}}, {{13,18}, EmptySpace{}}, {{14,18}, EmptySpace{}}, {{15,18}, EmptySpace{}}, {{16,18}, EmptySpace{}}, {{17,18}, EmptySpace{}}, {{18,18}, Wall{}}, {{19,18}, Wall{}},

    {{0,19}, Wall{}}, {{1,19}, Wall{}}, {{2,19}, Wall{}}, {{3,19}, Wall{}}, {{4,19}, Wall{}}, {{5,19}, Wall{}}, {{6,19}, Wall{}}, {{7,19}, Wall{}}, {{8,19}, Wall{}}, {{9,19}, Wall{}}, {{10,19}, Wall{}}, {{11,19}, Wall{}}, {{12,19}, Wall{}}, {{13,19}, Wall{}}, {{14,19}, Wall{}}, {{15,19}, Wall{}}, {{16,19}, Wall{}}, {{17,19}, Wall{}}, {{18,19}, Wall{}}, {{19,19}, Wall{}}

};
std::string map_link = "Map/Map.txt";
}; 