
#include "Include/System.hpp"
#include "iostream"


int main(){
    static System system;
    int is_ai_player;

    std::cout << " Enter 1 for AI player else Enter 0  ";
    std::cin >> is_ai_player;
    if (is_ai_player == 1){
        system.game_runner(true);
    }
    else if (is_ai_player == 0){
        system.game_runner(false);
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