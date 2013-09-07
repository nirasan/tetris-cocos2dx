#ifndef __tetris__Field__
#define __tetris__Field__

#include "Config.h"
#include "Chunk.h"

class Field
{
public:
    
    Block*** blocks;
    
    Field();
    ~Field();
};

#endif /* defined(__tetris__Field__) */
