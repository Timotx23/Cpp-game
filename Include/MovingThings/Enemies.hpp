
#pragma once
#include "map"
#include <vector>
#include <random>
#include "variant"


class EnememyMovements{
    private:
        std::random_device rd;
    public:
        std::pair<int, int> calculate_enemy_movement(std::pair<int, int> current_postion);

};

