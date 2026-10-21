#include "../Include/RaylibFrontend.hpp"

RaylibFrontend::RaylibFrontend(int tileSize)
    : tileSize(tileSize) {}

void RaylibFrontend::run(MapInformation& mapInfo) {
    const int mapWidth = 20;
    const int mapHeight = 20;

    const int screenWidth = mapWidth * tileSize;
    const int screenHeight = mapHeight * tileSize;

    InitWindow(screenWidth, screenHeight, "Maze Runner");
    SetTargetFPS(60);
    
    
}

void RaylibFrontend::drawMap(MapInformation& mapInfo) {
    auto& map = mapInfo.map_state.mazeMap;

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            auto& tile = map.at({x, y});

            Rectangle rect = {
                static_cast<float>(x * tileSize),
                static_cast<float>(y * tileSize),
                static_cast<float>(tileSize),
                static_cast<float>(tileSize)
            };

            
            if (std::holds_alternative<Wall>(tile)) {
                DrawRectangleRec(rect, DARKGRAY);
            }
            
            else if (std::holds_alternative<EndState>(tile)) {
                auto& endstate = std::get<EndState>(tile);
                DrawRectangleRec(rect, endstate.color);
                DrawText(endstate.sign.c_str(),x * tileSize + tileSize / 3,y * tileSize + tileSize / 4,tileSize / 2,WHITE);
            }
            else if (std::holds_alternative<EmptySpace>(tile)) {
                DrawRectangleRec(rect, RAYWHITE);
            }
            else if (std::holds_alternative<Player>(tile)) {
                auto& player = std::get<Player>(tile);
                DrawRectangleRec(rect, player.color);
                
                DrawText(player.sign.c_str(),
                        x * tileSize + tileSize / 3,
                        y * tileSize + tileSize / 4,
                        tileSize / 2,
                        WHITE);
            }
            else if (std::holds_alternative<Enemy>(tile)) {
                auto& enemy = std::get<Enemy>(tile);
                DrawRectangleRec(rect, enemy.color);
                
                DrawText(enemy.sign.c_str(),
                        x * tileSize + tileSize / 3,
                        y * tileSize + tileSize / 4,
                        tileSize / 2,
                        WHITE);
            }
            else if (std::holds_alternative<Chest>(tile)) {
                auto& chest = std::get<Chest>(tile);
                DrawRectangleRec(rect, chest.color);

                DrawText(chest.sign.c_str(),
                        x * tileSize + tileSize / 3,
                        y * tileSize + tileSize / 4,
                        tileSize / 2,
                        BLACK);
            }
            
            DrawRectangleLines(x * tileSize, y * tileSize, tileSize, tileSize,LIGHTGRAY );
                    }
                }
            }
