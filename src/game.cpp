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
  music = LoadMusicStream("../../resources/sound/music.mp3");
  PlayMusicStream(music);
  rotateSound = LoadSound("../../resources/sound/rotate.mp3");
  clearSound = LoadSound("../../resources/sound/clear.mp3");
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
  if(!gameOver){
    currentBlock.Draw(10, 10);

    // Set a base position for nextBlock
    int nextBlockX = 230;  // Default X position
    int nextBlockY = 259;  // Default Y position

    // Adjust the position based on currentBlock.codeColor
    switch(nextBlock.codeColor){
      	case 4: //Block O
          nextBlockX = 260;
          nextBlockY = 270;
          break;
        case 3: //Block I
          nextBlockX = 255;
          nextBlockY = 285;
          break;
        case 5: //Block S
          nextBlockX = 270;
          break;
        case 7: //Block Z
          nextBlockX = 240;
          break;
    	default:
          nextBlockX = 240;  // Keep the default position if no match
          break;
    }

    // Ensure nextBlock is positioned based on its size (for example, 32x32)
    nextBlock.Draw(nextBlockX, nextBlockY);
  }
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
      MoveBlockDown(true);
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

void Game::MoveBlockDown(bool fromSoftDrop){
  if(gameOver) return;

  currentBlock.Move(1, 0);

  if (IsBlockOutside() || !BlockFits()) {
    currentBlock.Move(-1, 0);  // undo
    LockBlock();
  } else {
    if (fromSoftDrop) {
      UpdateScore(0, 1);  // ajoute 1 point pour chaque descente
    }
  }
}

float Game::GetSpeedFromLevel(Level inputlevel){
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
    default:
  	  return constants::SPEED1;  // ou une valeur de secours
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
  int rowsCleared = grid.ClearFullRows();
  UpdateScore(rowsCleared, 0);
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
  score = 0;
}

bool Game::EventTriggered(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime > interval){
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

void Game::SetLevel(Level newLevel) {
    level = newLevel;
    speed = GetSpeedFromLevel(level);
}

void Game::UpdateScore(int linesCleared, int moveDownPoints){
  switch(linesCleared){
    case 1 :
      score += 40 * (static_cast<int>(level) + 1);
      break;
    case 2 :
      score += 100 * (static_cast<int>(level) + 1);
      break;
    case 3 :
      score += 300 * (static_cast<int>(level) + 1);
      break;
    case 4 :
      score += 1200 * (static_cast<int>(level) + 1);
      break;
    default: break;
    }
    score += moveDownPoints;
}

void Game::HandleSoftDrop() {
  if (IsKeyDown(KEY_DOWN)) {
    double currentTime = GetTime();
    if (currentTime - lastSoftDropTime >= softDropTime) {
      MoveBlockDown(); // reuse your existing function
      lastSoftDropTime = currentTime;
    }
  }
}

