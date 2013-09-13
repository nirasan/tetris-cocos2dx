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
    
    makeField();
    
    makeControlButton();
    
    startGame();
    
    return true;
}

void GameScene::makeField()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j <= FIELD_WIDTH_RIGHT_INDEX - FIELD_WIDTH_LEFT_INDEX; j++) {
            CCLabelTTF* b = CCLabelTTF::create("□", "Arial", 12.0);
            b->setPosition(ccp(winSize.width * (0.32 + j * 0.04), winSize.height * (0.1 + i * 0.04)));
            b->setColor(ccc3(128, 128, 128));
            this->addChild(b);
        }
    }
    
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
    game->moveLeft();
    moveChunk();
}

void GameScene::tapMoveRight()
{
    game->moveRight();
    moveChunk();
}

void GameScene::tapTurnLeft()
{
    game->chunk->turnLeft();
    moveChunk();
}

void GameScene::tapTurnRight()
{
    game->chunk->turnRight();
    moveChunk();
}

void GameScene::startGame()
{
    game = new Game();
    this->scheduleOnce(schedule_selector(GameScene::makeAndMoveChunk), 1);
}

void GameScene::makeChunk()
{
    int number = lastBlockNumber+1;
    int numbers[] = { number, number+1, number+2, number+3 };
    game->makeChunk(CHUNK_START_X, CHUNK_START_Y, numbers);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            if (game->chunk->blocks[i][j] != NULL) {
                CCLabelTTF* b = CCLabelTTF::create("■", "Arial", 12.0);
                int x = CHUNK_START_X - FIELD_WIDTH_LEFT_INDEX + j;
                int y = (FIELD_HEIGHT - 1) - (CHUNK_START_Y + i); // blocksの座標と画面の座標の開始位置が異なるので調整
                CCLOG("[makeChunk]=== x:%d y:%d", x, y);
                b->setPosition(ccp(winSize.width * (0.32 + x * 0.04), winSize.height * (0.1 + y * 0.04)));
                //b->setColor(ccc3(128, 128, 128));
                b->setTag(number);
                number++;
                this->addChild(b);
            }
        }
    }
    
    lastBlockNumber += 4;
}

void GameScene::moveUnder()
{
    // CCLOG("[moveUnder] x:%d y:%d", game->chunk->posX, game->chunk->posY);
    if (game->canMoveUnder()) {
        game->moveUnder();
        moveChunk();
    } else {
        game->copyBlocks();
        this->unschedule(schedule_selector(GameScene::moveUnder));
        deleteLines();
        this->scheduleOnce(schedule_selector(GameScene::makeAndMoveChunk), 1);
    }
}

void GameScene::moveChunk()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            if (game->chunk->blocks[i][j] != NULL) {
                Block* b = game->chunk->blocks[i][j];
                int number = b->getNumber();
                CCLabelTTF* l = (CCLabelTTF*)this->getChildByTag(number);
                int x = game->chunk->posX - FIELD_WIDTH_LEFT_INDEX + j;
                int y = (FIELD_HEIGHT - 1) - (game->chunk->posY + i);
                l->setPosition(ccp(winSize.width * (0.32 + x * 0.04), winSize.height * (0.1 + y * 0.04)));
                CCLOG("[showChunk]=== x:%d y:%d", x, y);
                // CCMoveTo* action = CCMoveTo::create(0.2, ccp(winSize.width * (0.32 + x * 0.04), winSize.height * (0.1 + y * 0.04)));
                // l->runAction(action);
            }
        }
    }
}

void GameScene::makeAndMoveChunk()
{
    makeChunk();
    this->schedule(schedule_selector(GameScene::moveUnder), 0.25);
}

void GameScene::deleteLines()
{
    if (game->checkDeletableLines())
    {
        for (int i = 0; i < FIELD_HEIGHT; i++)
        {
            if (game->deletableLines[i])
            {
                for (int j = 0; j < FIELD_WIDTH; j++)
                {
                    if (game->field->blocks[i][j] != NULL)
                    {
                        Block* b = game->field->blocks[i][j];
                        int number = b->getNumber();
                        
                        this->removeChildByTag(number);
                    }
                }
            }
        }
        
        game->deleteDeletableLines();
        
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        for (int i = 0; i < FIELD_HEIGHT; i++) {
            for (int j = 0; j < FIELD_WIDTH; j++) {
                if (game->field->blocks[i][j] != NULL) {
                    Block* b = game->field->blocks[i][j];
                    int number = b->getNumber();
                    CCLabelTTF* l = (CCLabelTTF*)this->getChildByTag(number);
                    int x = j - FIELD_WIDTH_LEFT_INDEX;
                    int y = (FIELD_HEIGHT - 1) - i;
                    CCMoveTo* action = CCMoveTo::create(0.2, ccp(winSize.width * (0.32 + x * 0.04), winSize.height * (0.1 + y * 0.04)));
                    l->runAction(action);
                }
            }
        }
    }
}
