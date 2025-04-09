//
// Created by giangvu on 4/8/25.
//

#ifndef BLOCK_H
#define BLOCK_H
#include <map>
#include "coord.h"
#include "colors.h"
#include "constants.h"

class Block {
protected:
    int codeColor;
    std::map<int, std::vector<Coord>> cells;
    Texture2D texture;

public:
    Block();

    //To manage 2D image or texture
    void LoadTexture(const char* filename);


    void Draw(int offsetX, int offsetY);
    void Draw();
    void Move(int rows, int columns);
    std::vector<Coord> GetCellPositions();
    void Rotate();
    void UndoRotation();



private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

#endif //BLOCK_H
