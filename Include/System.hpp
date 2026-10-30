#pragma once
#include "Map/Map.hpp"
#include "Map/BitMap.hpp"
#include "RaylibFrontend.hpp"
#include <variant>
#include <iostream>
#include "GameEngine.hpp"
#include "HYPERPARAMETERS.hpp"

class System{
    private:
        bool game_running = true;
        MapManager map_manager;
        RaylibFrontend frontend;
        GameEngine game_engine;
        
    public:
        void game_runner(bool is_ai_runner, HyperParameters hyperparameters);
        void run_game(MapInformation starting_state, bool is_ai);
        MapInformation load_map(int &number_chests, int &number_enemies, std::string &filename);
        void display_game(MapInformation &mapinfo);
        std::pair<bool, int> game_finished(std::vector<ObjectPosition> &player_pos, std::vector<ObjectPosition> &end_state, std::vector<ObjectPosition> &chests);
        std::pair<bool, int> can_continue(std::vector<ObjectPosition> &player_pos);
        MapInformation reset_map(MapInformation starting_state);

        

};