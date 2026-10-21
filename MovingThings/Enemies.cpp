#include "../Include/MovingThings/Enemies.hpp"

std::pair <int, int> EnememyMovements::calculate_enemy_movement(std::pair<int, int> current_postion){
    std::vector<std::pair<int, int>> possible_moves = {{current_postion.first+1, current_postion.second}, {current_postion.first-1, current_postion.second}, {current_postion.first, current_postion.second+1}, {current_postion.first,current_postion.second-1}}; 
   
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 3);
    
    int coords = distribution(generator);
    

    return possible_moves[coords];
}