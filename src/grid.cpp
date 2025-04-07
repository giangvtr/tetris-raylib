#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid() //This is the definition of a constructor for the Grid class.
{
    nbRows = 20;
    nbCols = 10;
    cellSize = CELL_SIZE;

    Initialize();
    colors = GetCellColors();
}


void Grid::Initialize(){
    for (int i=0;i<nbRows;i++){
        for(int j = 0; j<nbCols;j++){
            grid[i][j]=0;
        }
    }
}

void Grid::Print(){
    for (int i=0;i<nbRows;i++){
        for(int j = 0; j<nbCols;j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Grid::IsCellOutside(int row, int column){
  return (row < 0 || row>nbRows || column<0 || column>nbCols);
}

//Array access without boundary check in IsCellEmpty()
bool Grid::IsCellEmpty(int row, int column){
  if (IsCellOutside(row,column)) return false;
  return (grid[row][column] == 0);
}

//xem lai logic
int Grid::ClearFullRows(){
    int cleared = 0;
    for (int i=0;i<nbRows;i++){
        if(IsRowFull(i)){
          ClearRow(i);
          cleared++;
        }
        else if(cleared > 0) MoveRowDown(i,cleared);
    }
    return cleared;
}

bool Grid::IsRowFull(int row){
    for(int j=0;j<nbCols;j++){
      if(grid[row][j]==0) return false;
    }
  return true;
}

void Grid::ClearRow(int row){
  for(int j=0;j<nbCols;j++){
    grid[row][j]=0;
  }
}

void Grid::MoveRowDown(int row, int numRows){
  //copy the "row" to "row-numRows"
  for(int j=0;j<nbCols;j++){
    grid[row][j]=grid[row-numRows][j];
  }
}
