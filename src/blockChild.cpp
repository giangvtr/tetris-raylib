//
// Created by giangvu on 4/8/25.
//

#include "block.h"
#include "coord.h"

class LBlock: public Block{
  public:
    LBlock(){
      //Each type of block has a different color
      codeColor = 1;
      //Block L state 0 (no rotation). cells is a map of coordination
      cells[0]={Coord(0,2),Coord(1,0),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,1),Coord(1,1),Coord(2,1),Coord(2,2)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(1,2),Coord(2,0)};
      cells[3]={Coord(0,0),Coord(0,1),Coord(1,1),Coord(2,1)};
      //The block should appear in the middle of the upper bound of the grid
      this->Move(0,4);
    }
};

class BeBlock: public Block{
  public:
    BeBlock(){
      codeColor = 7;
      cells[0] = {Coord(0, 0)};
      cells[1] = {Coord(0, 0)};
      cells[2] = {Coord(0, 0)};
      cells[3] = {Coord(0, 0)};
      LoadTexture("../../resources/be.jpeg");
      Move(0,6);
    }
};

class JBlock: public Block{
  public:
    JBlock(){
      codeColor = 2;
      cells[0]={Coord(0, 0),Coord(1,0),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,1),Coord(0,2),Coord(1,1),Coord(2,2)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(1,2),Coord(2,2)};
      cells[3]={Coord(0,1),Coord(1,1),Coord(2,0),Coord(2,1)};
      this->Move(0,4);
    }
};

class IBlock: public Block{
  public:
    IBlock(){
      codeColor = 3;
      cells[0]={Coord(1, 0),Coord(1,1),Coord(1,2), Coord(1,3)};
      cells[1]={Coord(0,2),Coord(1,2),Coord(2,2),Coord(3,2)};
      cells[2]={Coord(2,0),Coord(2,1),Coord(2,2),Coord(2,3)};
      cells[3]={Coord(0,1),Coord(1,1),Coord(2,1),Coord(3,1)};
      this->Move(-1,3);
    }
};

class OBlock: public Block{
  public:
    OBlock(){
      codeColor = 4;
      cells[0]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      cells[1]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      cells[2]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      cells[3]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      this->Move(0,4);
    }
};

class SBlock: public Block{
  public:
    SBlock(){
      codeColor = 5;
      cells[0]={Coord(0,1),Coord(0,2),Coord(1,0), Coord(1,1)};
      cells[1]={Coord(0,1),Coord(1,1),Coord(1,2), Coord(2,2)};
      cells[2]={Coord(1,1),Coord(1,2),Coord(2,0), Coord(2,1)};
      cells[3]={Coord(2,0),Coord(1,0),Coord(1,1), Coord(2,1)};
      this->Move(0,3);
    }
};

class TBlock: public Block{
  public:
    TBlock(){
      codeColor = 6;
      cells[0]={Coord(0,1),Coord(1,0),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,1),Coord(1,1),Coord(1,2),Coord(2,1)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(1,2),Coord(2,1)};
      cells[3]={Coord(0,1),Coord(1,0),Coord(1,1), Coord(2,1)};
      this->Move(0,4);
    }
};

class ZBlock: public Block{
  public:
    ZBlock(){
      codeColor = 7;
      cells[0]={Coord(0,0),Coord(0,1),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,2),Coord(1,1),Coord(1,2),Coord(2,1)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(2,1),Coord(2,2)};
      cells[3]={Coord(1,0),Coord(1,1),Coord(1,0),Coord(2,0)};
      this->Move(0,4);
    }
};


