//
// Created by giangvu on 4/10/25.
//

#include "game.h"
#include <random>


//Make a constructor
Game::Game() {
  grid = Grid();
  blocks = RefillBlocks();
  gameOver = false;
  score = 0;
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();

  //For sounds
  InitAudioDevice();
  music = LoadMusicStream("Sounds/music.mp3");
  PlayMusicStream(music);
  rotateSound = LoadSound("Sounds/rotate.mp3");
  clearSound = LoadSound("Sounds/clear.mp3");
}

//Make a destructor
Game::~Game() {
  UnloadSound(rotateSound);
  UnloadSound(clearSound);
  UnloadMusicStream(music);
  CloseAudioDevice();

}

Block Game::GetRandomBlock() {
  //In case the pool of blocks is empty (because we are at the end of one cycle), refill them
  if(blocks.empty()){
    blocks = RefillBlocks();
  }

  int randomIndex=rand() % blocks.size();
  Block block = blocks[randomIndex];

  //Erase the chosen block from the pool so that it won't reappear again in the cycle
  blocks.erase(blocks.begin()+randomIndex);
  return block;
}

std::vector<Block> Game::RefillBlocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(),SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
  grid.Draw();
  if(!gameOver) currentBlock.Draw();
}

void Game::HandleInput(){
  int keyPressed = GetKeyPressed();
  if(gameOver && keyPressed == KEY_R){
    gameOver = false;
    Reset();
  }
  switch(keyPressed){
    case KEY_LEFT :
      MoveBlockLeft();
      break;
    case KEY_RIGHT :
      MoveBlockRight();
      break;
    case KEY_DOWN :
      MoveBlockDown();
      break;
    case KEY_UP :
      RotateBlock();
  }
}

void Game::MoveBlockLeft(){
  if (!gameOver){
    currentBlock.Move(0,-1);
    // if after moving, the block got out of the grid, move the block back in
    if(IsBlockOutside() || BlockFits()==false) MoveBlockRight();
  }
}

void Game::MoveBlockRight(){
  if(!gameOver){
    currentBlock.Move(0,1);
    if(IsBlockOutside() || BlockFits()==false) MoveBlockLeft();
  }
}

void Game::MoveBlockDown(){
  if(!gameOver){
    currentBlock.Move(1,0);
    if(IsBlockOutside() || BlockFits() == false){
      currentBlock.Move(-1,0);
      LockBlock();
    }
  }
}

float Game::GetSpeedFromLevel(Level level){
  switch(level){
    case Level::LEVEL1:
      return constants::SPEED1;
    case Level::LEVEL2:
      return constants::SPEED2;
    case Level::LEVEL3:
      return constants::SPEED3;
    case Level::LEVEL4:
      return constants::SPEED4;
    case Level::LEVEL5:
      return constants::SPEED5;
  }
}

bool Game::IsBlockOutside(){
  std::vector<Coord> tiles = currentBlock.GetCellPositions();
  for(Coord item: tiles){
    if(grid.IsCellOutside(item.row, item.col)){
      return true;
    }
  }
  return false;
}

void Game::RotateBlock(){
  currentBlock.Rotate();
  if(IsBlockOutside()) currentBlock.UndoRotation();
}

void Game::LockBlock(){
  //Get the coordination of each tile in currentBlock
  std::vector<Coord> tiles = currentBlock.GetCellPositions();

  //Update the grid where the currentBlock falls in
  //so the grid now hold the block color, not Darkgrey by default
  // we said now the grid is "occupied")
  for(Coord item: tiles){
    grid.grid[item.row][item.col] = currentBlock.GetBlockColor();

  }
  currentBlock = nextBlock;
  if(BlockFits() ==false){
    gameOver = true;
    return;
  }
  nextBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::BlockFits(){
  std::vector<Coord> tiles = currentBlock.GetCellPositions();
  for(Coord item: tiles){
    if(grid.IsCellEmpty(item.row, item.col) == false) return false;
  }
  return true;
}

void Game::Reset(){
  grid.Initialize();
  blocks = RefillBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

bool Game::EventTriggered(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime > interval){
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}
