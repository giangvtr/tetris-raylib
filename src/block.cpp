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
  std::vector<Coord> tiles = cells[rotationState];
  //For each tile of a block
  for(Coord item: tiles)
    if (texture.id != 0){
      Vector2 position = {static_cast<float>(item.col*cellSize+12), static_cast<float>(item.row*cellSize+7)};
      DrawTextureEx(texture, position, 0.0f, 0.013f, WHITE);
    } else{
      DrawRectangle(item.col*cellSize+5 , item.row*cellSize+5,cellSize - 1, cellSize - 1, colors[codeColor]);

    }
}

void Block::LoadTexture(const char* filename){
  if (texture.id != 0) { // Check if a previous texture exists
    UnloadTexture(texture); // Free GPU memory
  }
  texture = ::LoadTexture(filename); // Load new texture
}
