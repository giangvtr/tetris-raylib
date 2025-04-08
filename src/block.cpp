//
// Created by giangvu on 4/8/25.
//

#include "block.h"

Block::Block(){
  cellSize = constants::CELL_SIZE;
  rotationState=0;
  colors=GetCellColors();
}

void Block::Draw(){
  //Get the list of tiles within a block shape
  std::vector<Coordination> tiles = cells[rotationState];
  //For each tile of a block
  for(Coordination item: tiles)
    DrawRectangle(item.col*cellSize+5 , item.row*cellSize+5,cellSize - 1, cellSize - 1, colors[codeColor]);
}
