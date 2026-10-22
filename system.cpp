#include "Include/System.hpp"
#include <iostream>



void System::game_runner(bool is_ai_runner){
    
    MapInformation loadmap = load_map();
    frontend.run(loadmap);
    run_game(loadmap, is_ai_runner);
    /*
    load the map
    load the objects
    load starting position
    should start displaying the game
    if that all is done it should run the game
    */
};
std::pair <bool, int> System::game_finished(std::vector<ObjectPosition> &player_pos,std::vector<ObjectPosition> &end_state,std::vector<ObjectPosition> &chests  ){
    ObjectPosition player_position = player_pos[0];
    std::pair<int,int> end_state_pos = end_state[0].position;
    if (std::holds_alternative<Player>(player_position.name)) {
            Player& player = std::get<Player>(player_position.name);

            if (chests.size() == player.done_chests.size() && player_position.position == end_state_pos) {
                
                return {true, player.score};
            }
        }

    //if (player_position.position == end_state_pos  ){
    /*
    if (chests.size() == player.done_chests.size()){
            std::cout <<"It gets here for some reason " <<"\n";
            std::cout <<player_position.position.first << " " << player_position.position.second << "\n";
            std::cout << end_state_pos.first << " " << end_state_pos.second << "\n";
            return true;
        }
    */
        
    //}
    return {false, 0};
}



void System::display_game(MapInformation &mapInfo){

    BeginDrawing();
    ClearBackground(RAYWHITE);

    frontend.drawMap(mapInfo);

    EndDrawing();

}

MapInformation System::load_map(){
    MapInformation map =  map_manager.starting_position(3,5);
    
    return map;

};
std::pair < bool, int > System::can_continue(std::vector<ObjectPosition> &player_pos){
    if (player_pos.empty() || !std::holds_alternative<Player>(player_pos[0].name)) {
        return {true, 0};
    }
    Player& player = std::get<Player>(player_pos[0].name);
    if (player.number_of_lives > 0) {
        player.number_of_lives-= 1;
    }

    if (player.number_of_lives == 0) {
        return {false, 0};   // game over
    }
    return {true, player.number_of_lives};
}

MapInformation System::reset_map(MapInformation current_state){
    MapInformation resetet_map = map_manager.reset_map(current_state);


    return resetet_map;
}


void System::run_game(MapInformation game_state, bool is_ai){
    MapInformation original_state = game_state;
   
    std::pair<MapInformation,bool> new_state;
    std::cout<< "PLAYER STATS " << game_state.player[0].position.first <<" "<< game_state.player[0].position.second <<"\n";
    Player& player_data = std::get<Player>(game_state.player[0].name);
    std::cout<< "PLAYER Lives " << player_data.number_of_lives  <<"\n";
    while (game_running){
        
        new_state = game_engine.update_state(game_state, is_ai);
        //Check if state is winning state -> display score and Game Won message -> terminate window
        //check if its loosing state -> Display game over -> terminate window
        //check if the enemies killed it -> take off one life -> restart (reset only player and enemies to original position)
        
        
        std::pair<bool, int> is_finished = game_finished(new_state.first.player,new_state.first.endstate, new_state.first.treasures );
        
        if (is_finished.first){
            std::cout <<"Game finished" << "\n";
            std::cout <<"Score: " << is_finished.second <<"\n";
            game_running = false;
        }

        else if (new_state.second == false){
            std::cout <<"You died" << "\n";
            std::pair<bool, int> is_over = can_continue(new_state.first.player);
            if (is_over.first){
                std::cout << "You have " << is_over.second << " lives left" << "\n";
                new_state.first = reset_map(new_state.first);
            }
            else{
                std::cout << "GAME OVER" << "\n";
                game_running = false;
            }   
        }
        display_game(new_state.first); // This will always display the updated state
        game_state = new_state.first;
        
    }
    CloseWindow();
    
    
    /* Starting_state
    std::vector<ObjectPosition> enemies = generate_starting_postions("enemy", number_of_enemies);
    std::vector<ObjectPosition> chest = generate_starting_postions("chest", number_of_chests);
    std::vector<ObjectPosition> player = generate_starting_postions("player", 1);
    return MapInformation{enemies,chest,player,MapBitMap};
    
    */


    

}
