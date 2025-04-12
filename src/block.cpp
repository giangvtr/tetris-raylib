//
// Created by giangvu on 4/8/25.
//

#include "block.h"

Block::Block(){
  cellSize = constants::CELL_SIZE;
  rotationState=0;
  colors=GetCellColors();
  columnOffset = 0;
  rowOffset = 0;

}

void Block::Draw(){
  //Get the list of tiles within a block shape
  std::vector<Coord> tiles = GetCellPositions();
  //For each tile of a block

  for(Coord item: tiles)
    DrawRectangle(item.col*cellSize+10 , item.row*cellSize+10,cellSize - 1, cellSize - 1, colors[codeColor]);
}

void Block::LoadTexture(const char* filename){
  if (texture.id != 0) { // Check if a previous texture exists
    UnloadTexture(texture); // Free GPU memory
  }
  texture = ::LoadTexture(filename); // Load new texture
}

//Calculate the new position of the block after move();
//Starting by collecting the tiles included in current position
//Move each tile by an offset
std::vector<Coord> Block::GetCellPositions(){
  std::vector<Coord> tiles = this->cells[rotationState];
  std::vector<Coord> movedTiles;
  for (Coord item: tiles) {
    Coord newPosition = Coord(item.row + rowOffset, item.col + columnOffset);
    //Add this newly created coordination to the new tiles
    movedTiles.push_back(newPosition);
  }
  return movedTiles;
}

void Block::Rotate(){
  this->rotationState = (this->rotationState+1)%4;
}

void Block::UndoRotation(){
  this->rotationState = (this->rotationState-1)%4;
}

void Block::Move(int rows, int columns){
  rowOffset += rows;
  columnOffset += columns;
}

int Block::GetBlockColor(){
  return this->codeColor;
}