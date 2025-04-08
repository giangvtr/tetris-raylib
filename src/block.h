//
// Created by giangvu on 4/8/25.
//

#ifndef BLOCK_H
#define BLOCK_H
#include <map>
#include "coordination.h"
#include "colors.h"
#include "constants.h"

class Block {
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Draw();
    void Move(int rows, int columns);
    std::vector<Coordination> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int codeColor;
    std::map<int, std::vector<Coordination>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

#endif //BLOCK_H
