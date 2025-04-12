//
// Created by giangvu on 4/10/25.
//

/**
 * @file game.h
 * @brief Declaration of the Game class managing the Tetris game logic, rendering, and input.
 *
 * This class orchestrates the Tetris game flow using `Grid` and `Block` objects. It handles
 * user inputs, block generation, collision detection, scoring, and audio-visual feedback.
 */

#ifndef GAME_H
#define GAME_H
#include <raylib.h>
#include <vector>
#include "block.h"
#include "grid.h"
#include "blockChild.h"

/**
 * @class Game
 * @brief Core class that manages all aspects of the Tetris game.
 *
 * The Game class encapsulates game state, drawing, logic updates, and player interaction.
 * It contains private helper methods to control block behavior and detect game events.
 */
class Game {
public:
    /**
     * @brief Constructs a new Game object and initializes resources (e.g. block pool, sounds, grid).
     */
    Game();

    /**
     * @brief Destructor. Cleans up allocated resources like sounds/music.
     */
    ~Game();


    enum class Level {LEVEL1=0, LEVEL2, LEVEL3, LEVEL4, LEVEL5};




    /**
     * @brief Draws the current state of the game on the screen.
     *
     * Renders the grid, current and next blocks, and additional UI (score, game over, etc.).
     */
    void Draw();

    /**
     * @brief Handles player input (movement, rotation, etc.).
     *
     * This method polls input from the player and delegates block control accordingly.
     */
    void HandleInput();

    /**
     * @brief Moves the current block down by one row.
     *
     * If the block can no longer move downward (collides or reaches the grid bottom),
     * it is locked into the grid and a new block is spawned.
     */
    void MoveBlockDown(bool fromSoftDrop = false);

    /**
     * @brief Resets the game state to the beginning: score = 0, new grid, fresh blocks.
     */
    void Reset();

    bool EventTriggered(double interval);

    void SetLevel(Level newLevel);

    void HandleSoftDrop();


    // ==========THE PUBLIC ATTRIBUTES=============/
    /// Whether the game has ended due to the grid being filled.
    bool gameOver;

    /// The current score of the player, based on lines cleared and drops.
    int score;

    /// Background music for the game session.
    Music music;

    /// Time stamp to calculate falling block speed
    double lastUpdateTime = 0;

    Level level;

    float speed;



private:
    /**
     * @brief Moves the current block left by one column, if possible.
     */
    void MoveBlockLeft();

    /**
     * @brief Moves the current block right by one column, if possible.
     */
    void MoveBlockRight();

    /**
     * @brief Selects and returns a random block from the block pool.
     *
     * @return A randomly selected Block.
     */
    Block GetRandomBlock();

    /**
     * @brief Returns a list of all available Tetris blocks.
     *
     * @return Vector of Block objects representing possible Tetris shapes.
     */
    std::vector<Block> RefillBlocks();

    /**
     * @brief Checks whether the current block is outside the playable grid area.
     *
     * @return true if at least one tile is outside bounds; false otherwise.
     */
    bool IsBlockOutside();



    /**
     * @brief Attempts to rotate the current block clockwise.
     *
     * If the rotated block doesn't fit, the rotation is undone.
     */
    void RotateBlock();

    /**
     * @brief Locks the current block into the grid.
     * After locking, clears full lines, plays effects, updates score, and prepares the next block.
     */
    void LockBlock();

    /**
     * @brief Checks if the current block's position is valid (i.e., inside grid and not overlapping).
     *
     * @return true if the position is valid; false otherwise.
     */
    bool BlockFits();



    /**
     * @brief Updates the score based on the number of lines cleared and bonus for soft drop.
     *
     * @param linesCleared The number of lines cleared in a single move.
     * @param moveDownPoints Points awarded for soft dropping blocks.
     */
    void UpdateScore(int linesCleared, int moveDownPoints);

    float GetSpeedFromLevel(Level inputlevel);


    // ==================== THE PRIVATE ATTRIBUTES ===============
    /// The main grid where blocks fall and accumulate.
    Grid grid;

    /// All possible blocks (shapes) used in the game.
    std::vector<Block> blocks;

    /// The block currently being controlled by the player.
    Block currentBlock;

    /// The next block to be played, shown in preview.
    Block nextBlock;

    /// Sound effect played when the block is rotated.
    Sound rotateSound;

    /// Sound effect played when a line is cleared.
    Sound clearSound;

    float softDropTime = 0.05f;   // Time between drops while holding down
	double lastSoftDropTime = 0;  // Last time we moved down due to soft drop



}; // class Game

#endif //GAME_H
