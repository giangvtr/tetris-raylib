#include "grid.h"
#include <iostream>

Grid::Grid() //This is the definition of a constructor for the Grid class.
{
    nbRows = 20;
    nbCols = 10;
    cellSize = CELL_SIZE;

    Initialize();
}


void Grid::Initialize(){
    for (int i=0;i<HEIGHT;i++){
        for(int j = 0; j<WIDE;j++){
            grid[i][j]=0;
        }
    }
}

void Grid::Print(){
    for (int i=0;i<HEIGHT;i++){
        for(int j = 0; j<WIDE;j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Grid::IsCellOutside(int row, int column){
  return (row < 0 || row>HEIGHT || column<0 || column>WIDE);
}

//Array access without boundary check in IsCellEmpty()
bool Grid::IsCellEmpty(int row, int column){
  return (grid[row][column] == 0);
}

//xem lai logic
int Grid::ClearFullRows(){
    int cleared = 0;
    for (int i=0;i<HEIGHT;i++){
        if(IsRowFull(i)){
          ClearRow(i);
          cleared++;
        }
        else if(cleared > 0) MoveRowDown(i,cleared);
    }
    return cleared;
}

bool Grid::IsRowFull(int row){
    for(int j=0;j<WIDE;j++){
      if(grid[row][j]==0) return false;
    }
  return true;
}

void Grid::ClearRow(int row){
  for(int j=0;j<WIDE;j++){
    grid[row][j]=0;
  }
}

void Grid::MoveRowDown(int row, int numRows){
  //copy the "row" to "row-numRows"
  for(int j=0;j<WIDE;j++){
    grid[row][j]=grid[row-numRows][j];
  }
}

