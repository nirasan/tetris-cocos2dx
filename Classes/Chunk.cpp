#include "Chunk.h"
#include "Block.h"
#include "Config.h"

Chunk::Chunk()
:posX(0)
,posY(0)
{
    blocks = newBlocks();
    tmpBlocks = newBlocks();
}

Chunk::~Chunk()
{
    deleteBlocks(blocks);
    deleteBlocks(tmpBlocks);
}

void Chunk::setPos(int x, int y)
{
    posX = x;
    posY = y;
}

void Chunk::makeBlocks(Block ***b)
{
    int ids[] = {0, 1, 2, 3};
    makeBlocks(b, rand() % kShape_last, ids);
}

void Chunk::makeBlocks(Block ***b, int shape)
{
    int ids[] = {0, 1, 2, 3};
    makeBlocks(b, shape, ids);
}

void Chunk::makeBlocks(Block ***b, int shape, int ids[])
{
    int color = Block::kColor_White;
    
    switch (shape) {
        case kShape_o:
            b[1][1] = new Block(ids[0], color);
            b[1][2] = new Block(ids[1], color);
            b[2][1] = new Block(ids[2], color);
            b[2][2] = new Block(ids[3], color);
            break;
            
        case kShape_i:
            b[0][1] = new Block(ids[0], color);
            b[1][1] = new Block(ids[1], color);
            b[2][1] = new Block(ids[2], color);
            b[3][1] = new Block(ids[3], color);
            break;

        case kShape_t:
            b[1][1] = new Block(ids[0], color);
            b[2][1] = new Block(ids[1], color);
            b[2][2] = new Block(ids[2], color);
            b[3][1] = new Block(ids[3], color);
            break;
        
        case kShape_l:
            b[1][1] = new Block(ids[0], color);
            b[1][2] = new Block(ids[1], color);
            b[2][1] = new Block(ids[2], color);
            b[3][1] = new Block(ids[3], color);
            break;
        
        case kShape_rl:
            b[1][1] = new Block(ids[0], color);
            b[1][2] = new Block(ids[1], color);
            b[2][2] = new Block(ids[2], color);
            b[3][2] = new Block(ids[3], color);
            break;
            
        case kShape_z:
            b[1][2] = new Block(ids[0], color);
            b[2][1] = new Block(ids[1], color);
            b[2][2] = new Block(ids[2], color);
            b[3][1] = new Block(ids[3], color);
            break;
        
        case kShape_rz:
            b[1][1] = new Block(ids[0], color);
            b[2][1] = new Block(ids[1], color);
            b[2][2] = new Block(ids[2], color);
            b[3][2] = new Block(ids[3], color);
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
            delete b[i][j]; b[i][j] = NULL;
        }
        delete b[i]; b[i] = NULL;
    }
    delete b; b = NULL;
}

void Chunk::turnRight()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            int turned_x = CHUNK_WIDTH - 1 - i;
            int turned_y = j;
            tmpBlocks[turned_y][turned_x] = blocks[i][j];
        }
    }
    tmpToMain();
}

void Chunk::turnLeft()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            int turned_x = i;
            int turned_y = CHUNK_WIDTH - 1 -j;
            tmpBlocks[turned_y][turned_x] = blocks[i][j];
        }
    }
    tmpToMain();
}

void Chunk::tmpToMain()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            blocks[i][j] = tmpBlocks[i][j];
            tmpBlocks[i][j] = NULL;
        }
    }
}
