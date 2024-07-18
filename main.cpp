#include "raylib.h"
#include "grid.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime> 

#define fps 12

int main(void) {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed with current time
    Color darkGrey = { 25, 25, 25, 255 };

    const int screenWidth = 750;
    const int screenHeight = 750;
    const int cellSize = 10;

    InitWindow(screenWidth, screenHeight, "Conway's Game Of Life");
    Grid grid(screenWidth, screenHeight, cellSize);
    // for(int i = 0; i < screenHeight / cellSize; i++) {
    //     for(int j = 0; j < screenWidth / cellSize; j++) {
    //         float thing = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    //         grid.Point(i, j, thing < 0.5 ? 0 : 1);
    //     }
    // }

    grid.Point(10, 10, 1);
    grid.Point(9, 10, 1);
    grid.Point(10, 9, 1);
    grid.Point(11, 10, 1);
    grid.Point(11, 11, 1);
    grid.print();

    SetTargetFPS(fps);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkGrey);
        grid.Draw();
        grid.Update();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

