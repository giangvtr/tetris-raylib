//
// Created by giangvu on 4/10/25.
//

#ifndef BLOCKCHILD_H
#define BLOCKCHILD_H

#include "block.h"
#include "coord.h"

// LBlock: A child class of Block representing the 'L' shaped block
class LBlock : public Block {
public:
    LBlock();  // Constructor for LBlock
};

// TBlock: A child class of Block representing the 'T' shaped block
class TBlock : public Block {
public:
    TBlock();  // Constructor for TBlock
};

// BeBlock: A child class of Block representing the 'Be' shaped block (custom block name)
class BeBlock : public Block {
public:
    BeBlock();  // Constructor for BeBlock
};

// JBlock: A child class of Block representing the 'J' shaped block
class JBlock : public Block {
public:
    JBlock();  // Constructor for JBlock
};

// IBlock: A child class of Block representing the 'I' shaped block
class IBlock : public Block {
public:
    IBlock();  // Constructor for IBlock
};

// OBlock: A child class of Block representing the 'O' shaped block
class OBlock : public Block {
public:
    OBlock();  // Constructor for OBlock
};

// SBlock: A child class of Block representing the 'S' shaped block
class SBlock : public Block {
public:
    SBlock();  // Constructor for SBlock
};

// ZBlock: A child class of Block representing the 'Z' shaped block
class ZBlock : public Block {
public:
    ZBlock();  // Constructor for ZBlock
};

#endif // BLOCKCHILD_H
