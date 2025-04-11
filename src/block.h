/**
 * @file block.h
 * @brief Declaration of the Block class for handling Tetris-style pieces.
 *
 * This class represents a block made up of multiple cells (tiles),
 * which can be drawn, moved, and rotated. It supports both texture-based
 * and color-based rendering.
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include "coord.h"
#include "colors.h"
#include "constants.h"

/**
 * @class Block
 * @brief A class representing a game piece composed of multiple cells.
 *
 * Each block has a rotation state, an offset position within the game grid,
 * a color (or a texture), and methods to draw and manipulate its position
 * and orientation.
 */
class Block {
protected:
    int codeColor;  ///< Index used to select a color from the palette.
    std::map<int, std::vector<Coord>> cells; ///< Maps each rotation state to its corresponding cell positions.
    Texture2D texture; ///< Texture used for rendering the block (optional).

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the block with default cell size, rotation state, offsets,
     * and available colors.
     */
    Block();

    /**
     * @brief Loads a texture from an image file.
     * If a texture is already loaded, it will be unloaded first.
     * @param filename Path to the texture image file.
     */
    void LoadTexture(const char* filename);

    /**
     * @brief Draws the block at a specified pixel offset.
     *
     * @param offsetX Horizontal offset (in pixels).
     * @param offsetY Vertical offset (in pixels).
     */
    void Draw(int offsetX, int offsetY);

    /**
     * @brief Draws the block at its grid position where it should be based on offsets.
     */
    void Draw();

    /**
     * @brief Moves the block within the game grid.
     *
     * Adds row and column offsets to the current position.
     *
     * @param rows Number of rows to move.
     * @param columns Number of columns to move.
     */
    void Move(int rows, int columns);

    /**
     * @brief Returns the current cell positions of the block.
     *
     * Applies the current row and column offsets to each cell
     * based on the current rotation state.
     *
     * @return A vector of Coord representing the absolute positions of the block's cells.
     */
    std::vector<Coord> GetCellPositions();

    /**
     * @brief Rotates the block clockwise.
     *
     * Increments the rotation state (modulo 4).
     */
    void Rotate();

    /**
     * @brief Reverts the last rotation (counter-clockwise).
     *
     * Decrements the rotation state (modulo 4).
     */
    void UndoRotation();
    int GetBlockColor();


private:
    int cellSize; ///< Size of each cell (in pixels).
    int rotationState; ///< Current rotation index (0 to 3).
    std::vector<Color> colors; ///< List of available block colors.
    int rowOffset; ///< Vertical offset from the initial position.
    int columnOffset; ///< Horizontal offset from the initial position.
};

#endif // BLOCK_H
