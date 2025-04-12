#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid() //This is the definition of a constructor for the Grid class.
{
    nbRows = 20;
    nbCols = 10;
    cellSize = constants::CELL_SIZE;

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

void Grid::Draw()
{
    for (int row = 0; row < nbRows; row++)
    {
        for (int column = 0; column < nbCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 10, row * cellSize + 10, cellSize - 1, cellSize - 1, colors[cellValue]);
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
  if (row < 0 || row >= nbRows || column < 0 || column >= nbCols) return true;
  return false;
}

//Array access without boundary check in IsCellEmpty()
bool Grid::IsCellEmpty(int row, int column){
  if (IsCellOutside(row,column)) return false;
  //If the grid cell has other color than the default color
  //The grid is occupied
  return (grid[row][column] == 0);
}

//xem lai logic
int Grid::ClearFullRows(){
    int completed = 0;
    for (int row = nbRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0) MoveRowDown(row, completed);
    }
    return completed;
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
    grid[row+numRows][j]=grid[row][j];
    grid[row][j]=0;
  }
}
