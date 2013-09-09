#ifndef __tetris__GameScene__
#define __tetris__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::CCLayer
{
private:
    void makeControlButton();
    void tapMoveLeft();
    void tapMoveRight();
    void tapTurnLeft();
    void tapTurnRight();
    
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
};

#endif /* defined(__tetris__GameScene__) */
