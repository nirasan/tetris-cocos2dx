#include "GameScene.h"

using namespace cocos2d;
using namespace std;

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    GameScene* layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    makeControlButton();
    
    return true;
}

void GameScene::makeControlButton()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF* moveLeftLabel = CCLabelTTF::create("左", "Arial", 24.0);
    CCMenuItemLabel* moveLeft = CCMenuItemLabel::create(moveLeftLabel, this, menu_selector(GameScene::tapMoveLeft));
    moveLeft->setPosition(winSize.width * 0.1, winSize.height * 0.2);
    
    CCLabelTTF* moveRightLabel = CCLabelTTF::create("右", "Arial", 24.0);
    CCMenuItemLabel* moveRight = CCMenuItemLabel::create(moveRightLabel, this, menu_selector(GameScene::tapMoveRight));
    moveRight->setPosition(winSize.width * 0.2, winSize.height * 0.2);

    CCLabelTTF* turnLeftLabel = CCLabelTTF::create("左", "Arial", 24.0);
    CCMenuItemLabel* turnLeft = CCMenuItemLabel::create(turnLeftLabel, this, menu_selector(GameScene::tapTurnLeft));
    turnLeft->setPosition(winSize.width * 0.8, winSize.height * 0.2);
    
    CCLabelTTF* turnRightLabel = CCLabelTTF::create("右", "Arial", 24.0);
    CCMenuItemLabel* turnRight = CCMenuItemLabel::create(turnRightLabel, this, menu_selector(GameScene::tapTurnRight));
    turnRight->setPosition(winSize.width * 0.9, winSize.height * 0.2);
    
    CCMenu* menu = CCMenu::create(moveLeft, moveRight, turnLeft, turnRight, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
}

void GameScene::tapMoveLeft()
{
    
}

void GameScene::tapMoveRight()
{
    
}

void GameScene::tapTurnLeft()
{
    
}

void GameScene::tapTurnRight()
{
    
}
