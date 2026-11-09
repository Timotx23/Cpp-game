
#include "Include/System.hpp"
#include "Include/HYPERPARAMETERS.hpp"
#include "iostream"




int main(){
    static System system;
    HyperParameters hyperparameters;
    try{
        std::cout << " Enter 1 for AI player else Enter 0  ";
        if (!(std::cin >> hyperparameters.is_ai_player) || hyperparameters.is_ai_player != 0 && hyperparameters.is_ai_player != 1 ){
            throw std::invalid_argument("Choose number between 0 and 1 only!");
        }
    
    if (!hyperparameters.is_test_mode){
        std::cout << "Enter number of chests between 1 and 10: ";
        if (!(std::cin >> hyperparameters.CHESTS) || hyperparameters.CHESTS < 1 || hyperparameters.CHESTS > 10) {
            throw std::invalid_argument("Invalid number of chests!");
        }
        std::cout << "Enter number of Enemy players between 1 - 5: ";
        if (!(std::cin >> hyperparameters.ENEMIES) || hyperparameters.ENEMIES < 1 || hyperparameters.ENEMIES > 5 ) {
            throw std::invalid_argument("Invalid number of enemies!");
        }   
    }
    }
    
    catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
    }

    if (hyperparameters.is_ai_player == 1){
        system.game_runner(true,  hyperparameters);
    }
    else if (hyperparameters.is_ai_player == 0){
        system.game_runner(false, hyperparameters);
    } 
};

/*
things needed
select whether its human or ai based
chests
    - Give player 10 points for gathering
    - disapears after player collected it
player
    - has 3 lives at start of game
    - has a score function
    - can move 1 block at a time


enemies
    - instant kill on contact   
    - Total of 3 enemies are in the game at a time
    - can move 1 block at a time

If contact with enemy is made:
    - Player looses 1 life
    - Player returns to starting position 
    - score is preserved

scoring system:
    - 

Map layout:
P: Player
#: Wall
T: Treasure
E: Enemy
X: Exit
. or space: Empty cell
*/