#ifndef __tetris__Game__
#define __tetris__Game__

#include "Config.h"
#include "Block.h"
#include "Chunk.h"
#include "Field.h"

class Game
{
public:
    
    Field* field;
    Chunk* chunk;

    Game();
    ~Game();
    
    void moveLeft();
    void moveRight();
    void moveUnder();
    
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveUnder();
    
    void turnLeft();
    void turnRight();

    bool isConflict();
};

#endif /* defined(__tetris__Game__) */
