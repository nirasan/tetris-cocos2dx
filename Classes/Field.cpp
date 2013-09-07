#include "Field.h"
#include "Chunk.h"
#include "Block.h"

Field::Field()
{
    blocks = new Block**[FIELD_HEIGHT];
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        blocks[i] = new Block*[FIELD_WIDTH];
        for (int j = 0; j < FIELD_WIDTH; j++) {
            blocks[i][j] = NULL;
        }
    }
}

Field::~Field()
{
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            delete blocks[i][j]; blocks[i][j] = NULL;
        }
        delete blocks[i]; blocks[i] = NULL;
    }
    delete blocks; blocks = NULL;
}


