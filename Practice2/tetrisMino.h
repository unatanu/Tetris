#pragma once
#include "block.h"

class Mino
{
public:
    int x, y, rot, shape;
    Block* block[NUM];
    Mino(int x, int y, int rot, int shape);
    ~Mino();
    Mino* copyMino();
    void rotMino(Block* block[]);
    void draw();
};