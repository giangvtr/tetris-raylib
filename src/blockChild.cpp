//
// Created by giangvu on 4/8/25.
//

#include "block.h"
#include "coordination.h"

class LBlock: public Block{
  public:
    LBlock(){
      //Each type of block has a different color
      codeColor = 1;
      //Block L state 0 (no rotation). cells is a map of coordination
      cells[0]={Coordination(0,2),Coordination(1,0),Coordination(1,1), Coordination(1,2)};
      cells[1]={Coordination(0,1),Coordination(1,1),Coordination(2,1),Coordination(2,2)};
      cells[2]={Coordination(1,0),Coordination(1,1),Coordination(1,2),Coordination(2,0)};
      cells[3]={Coordination(0,0),Coordination(0,1),Coordination(1,1),Coordination(2,1)};
    }
};
