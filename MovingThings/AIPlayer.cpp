#include "../Include/MovingThings/AIPlayer.hpp"
#include "iostream"

std::pair<int,int> AIMovement::new_ai_player_pos(
    std::pair<int, int> ai_player_position,
    Map_info &map,
    std::pair<int, int> goal,
    int current_cost
){
    /* VIBECODED NEEED TO FIX LATER
        A*:
        f(n) = g(n) + h(n)

        g = cost from player start position
        h = estimated distance to goal (Manhattan distance)
    */

    struct Node {
        std::pair<int,int> position;
        int g_cost;
        int h_cost;
        int f_cost;
    };

    // Nodes that still need to be checked
    std::vector<Node> open_list;

    // Nodes already checked
    std::vector<std::pair<int,int>> closed_list;

    // Used to reconstruct the final path
    std::map<
        std::pair<int,int>,
        std::pair<int,int>
    > came_from;

    // Store cheapest known g-cost for each position
    std::map<std::pair<int,int>, int> g_costs;


    // Starting node
    int start_h =
        std::abs(goal.first - ai_player_position.first)
        +
        std::abs(goal.second - ai_player_position.second);

    Node start_node;

    start_node.position = ai_player_position;
    start_node.g_cost = current_cost;
    start_node.h_cost = start_h;
    start_node.f_cost = current_cost + start_h;

    open_list.push_back(start_node);

    g_costs[ai_player_position] = current_cost;


    while (!open_list.empty()) {

        // Find node with lowest f-cost
        int best_index = 0;

        for (int i = 1; i < open_list.size(); i++) {

            if (open_list[i].f_cost < open_list[best_index].f_cost) {
                best_index = i;
            }
        }


        Node current = open_list[best_index];

        // Remove it from open list
        open_list.erase(open_list.begin() + best_index);

        // Add to closed list
        closed_list.push_back(current.position);


        // -------------------------
        // GOAL FOUND
        // -------------------------

        if (current.position == goal) {

            std::pair<int,int> step = goal;

            /*
                Work backwards:

                Player -> A -> B -> C -> Goal

                Goal -> C -> B -> A

                Stop when A's parent is Player.

                Then return A.
            */

            while (came_from.find(step) != came_from.end() &&
                   came_from[step] != ai_player_position) {

                step = came_from[step];
            }
            std::cout <<"ITS DOING SOMETHING" <<"\n";
            return step;
        }


        // -------------------------
        // CHECK NEIGHBOURS
        // -------------------------

        for (int i = 0; i < movements.size(); i++) {

            std::pair<int,int> move = {
                current.position.first + movements[i].first,
                current.position.second + movements[i].second
            };


            auto tile = map.mazeMap.find(move);


            // Tile doesn't exist
            if (tile == map.mazeMap.end()) {
                continue;
            }


            // Cannot move through walls
            if (std::holds_alternative<Wall>(tile->second)) {
                continue;
            }


            // Ignore tiles already checked
            if (std::find(
                    closed_list.begin(),
                    closed_list.end(),
                    move
                ) != closed_list.end()) {

                continue;
            }


            // Each movement costs 1
            int new_g_cost = current.g_cost + 1;


            // Manhattan distance
            int h_cost =
                std::abs(goal.first - move.first)
                +
                std::abs(goal.second - move.second);


            int f_cost = new_g_cost + h_cost;


            /*
                If we haven't seen this tile before,
                OR this path is cheaper than the previous path.
            */

            if (g_costs.find(move) == g_costs.end() ||
                new_g_cost < g_costs[move]) {

                g_costs[move] = new_g_cost;

                came_from[move] = current.position;


                Node new_node;

                new_node.position = move;
                new_node.g_cost = new_g_cost;
                new_node.h_cost = h_cost;
                new_node.f_cost = f_cost;


                open_list.push_back(new_node);
            }
        }
    }


    // No path found
    return ai_player_position;
}