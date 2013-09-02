#include "Chunk.h"
#include "Block.h"
#include "Config.h"

Chunk::Chunk(int shape)
:posX(0)
,posY(0)
{
    /*
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        std::vector<Block*> v;
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            v.push_back(NULL);
        }
        blocks.push_back(v);
    }
    */
    blocks = new Block**[CHUNK_HEIGHT];
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        blocks[i] = new Block*[CHUNK_WIDTH];
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            blocks[i][j] = NULL;
        }
    }
    
    switch (shape) {
        case kShape_o:
            blocks[1][1] = new Block();
            blocks[1][2] = new Block();
            blocks[2][1] = new Block();
            blocks[2][2] = new Block();
            break;
            
        case kShape_i:
            blocks[0][1] = new Block();
            blocks[1][1] = new Block();
            blocks[2][1] = new Block();
            blocks[3][1] = new Block();
            break;

        case kShape_t:
            blocks[1][1] = new Block();
            blocks[2][1] = new Block();
            blocks[2][2] = new Block();
            blocks[3][1] = new Block();
            break;
        
        case kShape_l:
            blocks[1][1] = new Block();
            blocks[1][2] = new Block();
            blocks[2][1] = new Block();
            blocks[3][1] = new Block();
            break;
        
        case kShape_rl:
            blocks[1][1] = new Block();
            blocks[1][2] = new Block();
            blocks[2][2] = new Block();
            blocks[3][2] = new Block();
            break;
            
        case kShape_z:
            blocks[1][2] = new Block();
            blocks[2][1] = new Block();
            blocks[2][2] = new Block();
            blocks[3][1] = new Block();
            break;
        
        case kShape_rz:
            blocks[1][1] = new Block();
            blocks[2][1] = new Block();
            blocks[2][2] = new Block();
            blocks[3][2] = new Block();
            break;
            
        default:
            break;
    }
}

Chunk::~Chunk()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            delete blocks[i][j];
        }
        delete blocks[i];
    }
    delete blocks;
}

void Chunk::setPos(int x, int y)
{
    posX = x;
    posY = y;
}
