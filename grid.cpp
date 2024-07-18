#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include "grid.hpp"

void Grid::Draw() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            Color color = grid[i][j] == 1 ? DARKGRAY : RAYWHITE; 
            DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, color);
        }
    }
}

void Grid::randomize() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            float thing = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            grid[i][j] = (thing < 0.5 ? 0 : 1);
        }
    }
}

void Grid::Point(int row, int col, int target) {
    grid[row][col] = target;
}

void Grid::Update() {
    int temp[rows][cols]; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; 
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        if (grid[ni][nj] == 1) {
                            neighbors++;
                        }
                    }
                }
            }
            if (grid[i][j] == 1) {
                temp[i][j] = (neighbors < 2 || neighbors > 3) ? 0 : 1;
            } else {
                temp[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

void Grid::print() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
