
#include <map>
#include <utility>
#include <variant>
#include "../Objects/Objects.hpp"
std::map<std::pair<int, int>, std::variant<EmptySpace, Wall, Player, EndState, Enemy, Chest>> mazeMap = {{8, 10}, EmptySpace{}}, {{9, 10}, EmptySpace{}}, {{10, 10}, EmptySpace{}}, {{11, 10}, EmptySpace{}},
    {{12, 10}, Wall{}}, {{13, 10}, EmptySpace{}}, {{14, 10}, Wall{}}, {{15, 10}, EmptySpace{}},
    {{16, 10}, EmptySpace{}}, {{17, 10}, Wall{}}, {{18, 10}, EmptySpace{}}, {{19, 10}, Wall{}},
    // y = 11
    {{0, 11}, Wall{}}, {{1, 11}, EmptySpace{}}, {{2, 11}, EmptySpace{}}, {{3, 11}, Wall{}},
    {{4, 11}, EmptySpace{}}, {{5, 11}, Wall{}}, {{6, 11}, EmptySpace{}}, {{7, 11}, EmptySpace{}},
    {{8, 11}, Wall{}}, {{9, 11}, EmptySpace{}}, {{10, 11}, EmptySpace{}}, {{11, 11}, Wall{}},
    {{12, 11}, EmptySpace{}}, {{13, 11}, Wall{}}, {{14, 11}, EmptySpace{}}, {{15, 11}, EmptySpace{}},
    {{16, 11}, EmptySpace{}}, {{17, 11}, EmptySpace{}}, {{18, 11}, EmptySpace{}}, {{19, 11}, Wall{}},
    // y = 12
    {{0, 12}, Wall{}}, {{1, 12}, EmptySpace{}}, {{2, 12}, EmptySpace{}}, {{3, 12}, EmptySpace{}},
    {{4, 12}, EmptySpace{}}, {{5, 12}, EmptySpace{}}, {{6, 12}, EmptySpace{}}, {{7, 12}, EmptySpace{}},
    {{8, 12}, EmptySpace{}}, {{9, 12}, EmptySpace{}}, {{10, 12}, EmptySpace{}}, {{11, 12}, EmptySpace{}},
    {{12, 12}, Wall{}}, {{13, 12}, Wall{}}, {{14, 12}, EmptySpace{}}, {{15, 12}, EmptySpace{}},
    {{16, 12}, EmptySpace{}}, {{17, 12}, EmptySpace{}}, {{18, 12}, EmptySpace{}}, {{19, 12}, Wall{}},
    // y = 13
    {{0, 13}, Wall{}}, {{1, 13}, EmptySpace{}}, {{2, 13}, EmptySpace{}}, {{3, 13}, Wall{}},
    {{4, 13}, EmptySpace{}}, {{5, 13}, EmptySpace{}}, {{6, 13}, EmptySpace{}}, {{7, 13}, EmptySpace{}},
    {{8, 13}, Wall{}}, {{9, 13}, EmptySpace{}}, {{10, 13}, EmptySpace{}}, {{11, 13}, EmptySpace{}},
    {{12, 13}, Wall{}}, {{13, 13}, EmptySpace{}}, {{14, 13}, Wall{}}, {{15, 13}, EmptySpace{}},
    {{16, 13}, EmptySpace{}}, {{17, 13}, Wall{}}, {{18, 13}, EmptySpace{}}, {{19, 13}, Wall{}},
    // y = 14
    {{0, 14}, Wall{}}, {{1, 14}, EmptySpace{}}, {{2, 14}, EmptySpace{}}, {{3, 14}, EmptySpace{}},
    {{4, 14}, EmptySpace{}}, {{5, 14}, EmptySpace{}}, {{6, 14}, EmptySpace{}}, {{7, 14}, EmptySpace{}},
    {{8, 14}, Wall{}}, {{9, 14}, EmptySpace{}}, {{10, 14}, EmptySpace{}}, {{11, 14}, EmptySpace{}},
    {{12, 14}, EmptySpace{}}, {{13, 14}, EmptySpace{}}, {{14, 14}, EmptySpace{}}, {{15, 14}, EmptySpace{}},
    {{16, 14}, EmptySpace{}}, {{17, 14}, EmptySpace{}}, {{18, 14}, EmptySpace{}}, {{19, 14}, Wall{}},
    // y = 15
    {{0, 15}, Wall{}}, {{1, 15}, EmptySpace{}}, {{2, 15}, EmptySpace{}}, {{3, 15}, EmptySpace{}},
    {{4, 15}, EmptySpace{}}, {{5, 15}, EmptySpace{}}, {{6, 15}, EmptySpace{}}, {{7, 15}, EmptySpace{}},
    {{8, 15}, EmptySpace{}}, {{9, 15}, Wall{}}, {{10, 15}, EmptySpace{}}, {{11, 15}, Wall{}},
    {{12, 15}, EmptySpace{}}, {{13, 15}, EmptySpace{}}, {{14, 15}, EmptySpace{}}, {{15, 15}, EmptySpace{}},
    {{16, 15}, Wall{}}, {{17, 15}, EmptySpace{}}, {{18, 15}, Wall{}}, {{19, 15}, Wall{}},
    // y = 16
    {{0, 16}, Wall{}}, {{1, 16}, EmptySpace{}}, {{2, 16}, EmptySpace{}}, {{3, 16}, EmptySpace{}},
    {{4, 16}, EmptySpace{}}, {{5, 16}, EmptySpace{}}, {{6, 16}, EmptySpace{}}, {{7, 16}, EmptySpace{}},
    {{8, 16}, EmptySpace{}}, {{9, 16}, EmptySpace{}}, {{10, 16}, Wall{}}, {{11, 16}, EmptySpace{}},
    {{12, 16}, EmptySpace{}}, {{13, 16}, EmptySpace{}}, {{14, 16}, Wall{}}, {{15, 16}, EmptySpace{}},
    {{16, 16}, EmptySpace{}}, {{17, 16}, EmptySpace{}}, {{18, 16}, EmptySpace{}}, {{19, 16}, Wall{}},
    // y = 17
    {{0, 17}, Wall{}}, {{1, 17}, EmptySpace{}}, {{2, 17}, Wall{}}, {{3, 17}, EmptySpace{}},
    {{4, 17}, EmptySpace{}}, {{5, 17}, EmptySpace{}}, {{6, 17}, EmptySpace{}}, {{7, 17}, EmptySpace{}},
    {{8, 17}, EmptySpace{}}, {{9, 17}, EmptySpace{}}, {{10, 17}, EmptySpace{}}, {{11, 17}, Wall{}},
    {{12, 17}, EmptySpace{}}, {{13, 17}, EmptySpace{}}, {{14, 17}, EmptySpace{}}, {{15, 17}, EmptySpace{}},
    {{16, 17}, EmptySpace{}}, {{17, 17}, EmptySpace{}}, {{18, 17}, EmptySpace{}}, {{19, 17}, Wall{}},
    // y = 18
    {{0, 18}, Wall{}}, {{1, 18}, EmptySpace{}}, {{2, 18}, EmptySpace{}}, {{3, 18}, EmptySpace{}},
    {{4, 18}, EmptySpace{}}, {{5, 18}, EmptySpace{}}, {{6, 18}, EmptySpace{}}, {{7, 18}, EmptySpace{}},
    {{8, 18}, EmptySpace{}}, {{9, 18}, EmptySpace{}}, {{10, 18}, EmptySpace{}}, {{11, 18}, EmptySpace{}},
    {{12, 18}, EmptySpace{}}, {{13, 18}, Wall{}}, {{14, 18}, EmptySpace{}}, {{15, 18}, EmptySpace{}},
    {{16, 18}, EmptySpace{}}, {{17, 18}, EmptySpace{}}, {{18, 18}, EmptySpace{}}, {{19, 18}, Wall{}},
    // y = 19
    {{0, 19}, Wall{}}, {{1, 19}, Wall{}}, {{2, 19}, Wall{}}, {{3, 19}, Wall{}},
    {{4, 19}, Wall{}}, {{5, 19}, Wall{}}, {{6, 19}, Wall{}}, {{7, 19}, Wall{}},
    {{8, 19}, Wall{}}, {{9, 19}, Wall{}}, {{10, 19}, Wall{}}, {{11, 19}, Wall{}},
    {{12, 19}, Wall{}}, {{13, 19}, Wall{}}, {{14, 19}, Wall{}}, {{15, 19}, Wall{}},
    {{16, 19}, Wall{}}, {{17, 19}, Wall{}}, {{18, 19}, Wall{}}, {{19, 19}, Wall{}};