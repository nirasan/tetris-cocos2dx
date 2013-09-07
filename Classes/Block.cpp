#include "Block.h"

Block::Block(int number, int color)
:number(number)
,color(color)
{
}

Block::~Block()
{
}

int Block::getNumber()
{
    return number;
}

int Block::getColor()
{
    return color;
}