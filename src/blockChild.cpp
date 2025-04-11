//
// Created by giangvu on 4/8/25.
//

#include "blockChild.h"

LBlock::LBlock(){
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

BeBlock::BeBlock(){
      codeColor = 7;
      cells[0] = {Coord(0, 0)};
      cells[1] = {Coord(0, 0)};
      cells[2] = {Coord(0, 0)};
      cells[3] = {Coord(0, 0)};
      LoadTexture("../../resources/img/be.jpeg");
      Move(0,6);
}

JBlock::JBlock(){
      codeColor = 2;
      cells[0]={Coord(0, 0),Coord(1,0),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,1),Coord(0,2),Coord(1,1),Coord(2,1)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(1,2),Coord(2,2)};
      cells[3]={Coord(0,1),Coord(1,1),Coord(2,0),Coord(2,1)};
      this->Move(0,4);
}

IBlock::IBlock(){
      codeColor = 3;
      cells[0]={Coord(1, 0),Coord(1,1),Coord(1,2), Coord(1,3)};
      cells[1]={Coord(0,2),Coord(1,2),Coord(2,2),Coord(3,2)};
      cells[2]={Coord(2,0),Coord(2,1),Coord(2,2),Coord(2,3)};
      cells[3]={Coord(0,1),Coord(1,1),Coord(2,1),Coord(3,1)};
      this->Move(-1,3);
}

OBlock::OBlock(){
      codeColor = 4;
      cells[0]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      cells[1]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      cells[2]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      cells[3]={Coord(0,0),Coord(0,1),Coord(1,0), Coord(1,1)};
      this->Move(0,4);
}

SBlock::SBlock(){
      codeColor = 5;
      cells[0]={Coord(0,1),Coord(0,2),Coord(1,0), Coord(1,1)};
      cells[1]={Coord(0,1),Coord(1,1),Coord(1,2), Coord(2,2)};
      cells[2]={Coord(1,1),Coord(1,2),Coord(2,0), Coord(2,1)};
      cells[3]={Coord(2,0),Coord(1,0),Coord(1,1), Coord(2,1)};
      this->Move(0,3);
    }

TBlock::TBlock(){
      codeColor = 6;
      cells[0]={Coord(0,1),Coord(1,0),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,1),Coord(1,1),Coord(1,2),Coord(2,1)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(1,2),Coord(2,1)};
      cells[3]={Coord(0,1),Coord(1,0),Coord(1,1), Coord(2,1)};
      this->Move(0,4);
}

ZBlock::ZBlock(){
      codeColor = 7;
      cells[0]={Coord(0,0),Coord(0,1),Coord(1,1), Coord(1,2)};
      cells[1]={Coord(0,2),Coord(1,1),Coord(1,2),Coord(2,1)};
      cells[2]={Coord(1,0),Coord(1,1),Coord(2,1),Coord(2,2)};
      cells[3]={Coord(1,0),Coord(1,1),Coord(1,0),Coord(2,0)};
      this->Move(0,4);
}


