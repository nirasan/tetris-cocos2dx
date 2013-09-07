#include "Chunk.h"
#include "Block.h"
#include "Config.h"

Chunk::Chunk()
:posX(0)
,posY(0)
{
    blocks = newBlocks();
}

void Chunk::makeBlocks(Block ***b)
{
    makeBlocks(b, rand() % kShape_last);
}

void Chunk::makeBlocks(Block ***b, int shape)
{
    switch (shape) {
        case kShape_o:
            b[1][1] = new Block();
            b[1][2] = new Block();
            b[2][1] = new Block();
            b[2][2] = new Block();
            break;
            
        case kShape_i:
            b[0][1] = new Block();
            b[1][1] = new Block();
            b[2][1] = new Block();
            b[3][1] = new Block();
            break;

        case kShape_t:
            b[1][1] = new Block();
            b[2][1] = new Block();
            b[2][2] = new Block();
            b[3][1] = new Block();
            break;
        
        case kShape_l:
            b[1][1] = new Block();
            b[1][2] = new Block();
            b[2][1] = new Block();
            b[3][1] = new Block();
            break;
        
        case kShape_rl:
            b[1][1] = new Block();
            b[1][2] = new Block();
            b[2][2] = new Block();
            b[3][2] = new Block();
            break;
            
        case kShape_z:
            b[1][2] = new Block();
            b[2][1] = new Block();
            b[2][2] = new Block();
            b[3][1] = new Block();
            break;
        
        case kShape_rz:
            b[1][1] = new Block();
            b[2][1] = new Block();
            b[2][2] = new Block();
            b[3][2] = new Block();
            break;
            
        default:
            break;
    }
}

Block*** Chunk::newBlocks()
{
    Block*** b = new Block**[CHUNK_HEIGHT];
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        b[i] = new Block*[CHUNK_WIDTH];
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            b[i][j] = NULL;
        }
    }
    return b;
}

void Chunk::deleteBlocks(Block ***b)
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            delete b[i][j];
        }
        delete b[i];
    }
    delete b;
}

Chunk::~Chunk()
{
    deleteBlocks(blocks);
}

void Chunk::setPos(int x, int y)
{
    posX = x;
    posY = y;
}
