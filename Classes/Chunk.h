#ifndef __tetris__Chunk__
#define __tetris__Chunk__

#include <vector>
#include "Block.h"

class Chunk
{
public:
    
    int posX;
    int posY;
    //std::vector< std::vector<Block*> > blocks;
    Block*** blocks;
    
    enum kShape {
        kShape_o,
        kShape_i,
        kShape_t,
        kShape_l,
        kShape_rl,
        kShape_z,
        kShape_rz,
    };
    
    Chunk(int shape);
    ~Chunk();
    
    void setPos(int x, int y);
};

#endif /* defined(__tetris__Chunk__) */
