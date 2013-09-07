#ifndef __tetris__Chunk__
#define __tetris__Chunk__

#include <vector>
#include "Block.h"

class Chunk
{
public:
    
    int posX;
    int posY;
    Block*** blocks;
    
    enum kShape {
        kShape_o,
        kShape_i,
        kShape_t,
        kShape_l,
        kShape_rl,
        kShape_z,
        kShape_rz,
        kShape_last,
    };
    
    Chunk();
    ~Chunk();
    
    Block*** newBlocks();
    void deleteBlocks(Block*** b);
    void updateBlocks(Block*** b);
    
    static void makeBlocks(Block*** b);
    static void makeBlocks(Block*** b, int shape);
    static void makeBlocks(Block*** b, int shape, int numbers[]);
    
    Block*** makeTurnedRightBlocks();
    Block*** makeTurnedLeftBlocks();
    
    void setPos(int x, int y);
};

#endif /* defined(__tetris__Chunk__) */
