#ifndef __tetris__Game__
#define __tetris__Game__

#include "Config.h"
#include "Block.h"
#include "Chunk.h"
#include "Field.h"

class Game
{
private:
    Field* field;
    Chunk* chunk;
    
public:
    Game();
    ~Game();
    
    void moveLeft();
    void moveRight();
    void moveDown();
    
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveDown();
    
    void turnLeft();
    void turnRight();

    bool isConflict();
};

#endif /* defined(__tetris__Game__) */
