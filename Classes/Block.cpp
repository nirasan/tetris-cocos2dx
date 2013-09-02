#include "Block.h"

Block::Block()
:color(kColor_White)
{
}

Block::~Block()
{
}

int Block::getColor()
{
    return color;
}