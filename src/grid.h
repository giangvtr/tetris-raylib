
//Ensure that this header file is only included once in a compilation
#pragma once

#include <vector>
#include <raylib.h>
#include "constants.h"

/**
 * @brief Represents the game grid used for block-based games like Tetris.
 *
 * The grid holds integer values representing the color index of blocks.
 * A value of 0 indicates that the cell is empty.
 */
class Grid {
    public:
        /**
         * @brief 2D array representing the grid state.
         *
         * Each cell contains an integer:
         * - 0 means the cell is empty.
         * - A positive number is an index into the colors vector, representing a block.
         */
        int grid[constants::HEIGHT][constants::WIDTH];
    
        /**
         * @brief Constructs a Grid object with default dimensions and cell size.
         */
        Grid();
    
        /**
         * @brief Resets the grid to an empty state.
         *
         * Sets every cell in the grid to 0, meaning all positions are empty (no block present).
         * Useful at the beginning of the game or when restarting.
         */
        void Initialize();
    
        /**
         * @brief Prints the grid values to the console.
         *
         * Displays each cell’s current value for debugging purposes.
         * Used mainly during development when visual output is not required.
         */
        void Print();
    
        /**
         * @brief Renders the grid on the screen using raylib.
         *
         * Each non-zero cell is drawn as a filled rectangle using its corresponding color.
         * Grid borders and spacing may also be rendered depending on implementation.
         */
        void Draw();
    
        /**
         * @brief Checks if the specified cell is outside the bounds of the grid.
         *
         * @param row Row index to check.
         * @param column Column index to check.
         * @return true if the cell is outside the grid dimensions; false otherwise.
         */
        bool IsCellOutside(int row, int column);
    
        /**
         * @brief Checks if the specified cell is empty.
         *
         * A cell is considered empty if its value is 0.
         *
         * @param row Row index of the cell.
         * @param column Column index of the cell.
         * @return true if the cell contains 0; false if it contains a block (non-zero).
         */
        bool IsCellEmpty(int row, int column);
    
        /**
         * @brief Clears all full rows and shifts upper rows downward.
         *
         * A row is considered full if all of its cells contain non-zero values.
         * Cleared rows are replaced with empty rows at the top of the grid.
         *
         * @return The total number of rows cleared.
         */
        int ClearFullRows();
    
        
    
    private:
        
        /**
         * @brief Checks whether a row is completely filled with blocks.
         *
         * @param row The index of the row to evaluate.
         * @return true if all cells in the row are non-zero; false otherwise.
         */
        bool IsRowFull(int row);
    
        /**
         * @brief Clears all blocks from a given row by setting all cells to 0.
         *
         * @param row The index of the row to clear.
         */
        void ClearRow(int row);
    
        /**
         * @brief Moves a row down by a specified number of positions.
         *
         * The contents of the specified row are copied downward by `numRows` rows.
         *
         * @param row The index of the row to move.
         * @param numRows Number of rows to shift down.
         */
        void MoveRowDown(int row, int numRows);
    
        /**
         * @brief Number of rows in the grid (default: 20).
         */
        int nbRows;
    
        /**
         * @brief Number of columns in the grid (default: 10).
         */
        int nbCols;
    
        /**
         * @brief Pixel size of each square cell.
         */
        int cellSize;
    
        /**
         * @brief Color palette where each index corresponds to a block color.
         *
         * Index 0 is usually reserved for the empty cell color.
         */
        std::vector<Color> colors;
    };