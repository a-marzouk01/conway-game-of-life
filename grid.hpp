#pragma once
#include <vector>

class Grid {
private:
    int rows, cols, cellSize;
    std::vector<std::vector<int>> grid;

public:
    Grid(int width, int height, int cellSize)
    : rows(height / cellSize), cols(width / cellSize), cellSize(cellSize), grid(rows, std::vector<int>(cols, 0)) {};

    void Draw();
    void randomize();
    void Point(int row, int col, int target);
    void Update();
    void print();

};
