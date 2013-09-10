#ifndef __tetris__GameScene__
#define __tetris__GameScene__

#include "cocos2d.h"
#include "Game.h"

class GameScene : public cocos2d::CCLayer
{
private:
    Game* game;
    int lastBlockNumber = 0;
    
    void makeField();
    
    void makeControlButton();
    void tapMoveLeft();
    void tapMoveRight();
    void tapTurnLeft();
    void tapTurnRight();
    
    void startGame();
    
    void makeChunk();
    void moveChunk();
    
    void moveUnder();
    
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
};

#endif /* defined(__tetris__GameScene__) */
