#include "Game.h"
#include "Config.h"
#include "cocos2d.h"

USING_NS_CC;

Game::Game()
{
    field = new Field();
    chunk = new Chunk();
    deletableLines = new bool[FIELD_HEIGHT];
    for (int i = 0; i < FIELD_HEIGHT; i++) deletableLines[i] = false;
}

Game::~Game()
{
    delete field;
    delete chunk;
    delete[] deletableLines;
}

void Game::moveLeft()
{
    if (canMoveLeft())
        chunk->posX = chunk->posX - 1;
}

void Game::moveRight()
{
    if (canMoveRight())
        chunk->posX = chunk->posX + 1;
}

void Game::moveUnder()
{
    if (canMoveUnder()) {
        chunk->posY = chunk->posY + 1;
        
        copyBlocks();
    }
}

bool Game::canMoveLeft()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            if (chunk->blocks[i][j] != NULL) {
                int leftX = chunk->posX + j - 1;
                if (leftX < FIELD_WIDTH_LEFT_INDEX) return false;
                if (field->blocks[i][leftX] != NULL) return false;
                break;                
            }
        }
    }
    return true;
}

bool Game::canMoveRight()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = CHUNK_WIDTH - 1; j > 0; j--) {
            if (chunk->blocks[i][j] != NULL) {
                int rightX = chunk->posX + j + 1;
                if (rightX > FIELD_WIDTH_RIGHT_INDEX) return false;
                if (field->blocks[i][rightX] != NULL) return false;
                break;
            }
        }
    }
    return true;
}

bool Game::canMoveUnder()
{
    bool checked = false;
    for (int i = 0; i < CHUNK_WIDTH; i++) {
        for (int j = CHUNK_HEIGHT - 1; j > 0; j--) {
            if (chunk->blocks[i][j] != NULL) {
                int underY = chunk->posY + j + 1;
                if (underY > FIELD_HEIGHT - 1) return false;
                if (field->blocks[underY][i] != NULL) return false;
                checked = true;
                break;
            }
        }
    }
    return checked;
}

void Game::copyBlocks()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            int y = i + chunk->posY;
            int x = j + chunk->posX;
            if (chunk->blocks[i][j] != NULL) {
                field->blocks[y][x] = chunk->blocks[i][j];
                chunk->blocks[i][j] = NULL;
            }
        }
    }
}

void Game::turnLeft()
{
    chunk->turnLeft();
    if (isConflict()) {
        chunk->turnRight();
    }
}

void Game::turnRight()
{
    chunk->turnRight();
    if (isConflict()) {
        chunk->turnLeft();
    }
}

bool Game::isConflict()
{
    for (int i = 0; i < CHUNK_HEIGHT; i++) {
        for (int j = 0; j < CHUNK_WIDTH; j++) {
            int y = i + chunk->posY;
            int x = j + chunk->posX;
            if (chunk->blocks[i][j] != NULL) {
                CCLOG("===== i:%d j:%d x:%d y:%d", i, j, x, y);
                if (y < 0 || FIELD_HEIGHT-1 < y) return true;
                CCLOG("===== %d", 1);
                if (x < FIELD_WIDTH_LEFT_INDEX || FIELD_WIDTH_RIGHT_INDEX < x) return true;
                CCLOG("===== %d", 2);
                if (field->blocks[y][x] != NULL) return true;
                CCLOG("===== %d", 3);
            }
        }
    }
    return false;
}

void Game::checkDeletableLines()
{
    for (int i = 1; i < FIELD_HEIGHT; i++) {
        deletableLines[i] = false;
        bool check = true;
        for (int j = FIELD_WIDTH_LEFT_INDEX; j <= FIELD_WIDTH_RIGHT_INDEX; j++) {
            if (field->blocks[i][j] == NULL) {
                CCLOG("[checkDeletableLines] x:%d y:%d is NULL", j, i);
                check = false;
                break;
            }
        }
        if (check) deletableLines[i] = true;
    }
}

void Game::deleteDeletableLines()
{
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        if (!deletableLines[i]) continue;
        // delete blocks
        for (int j = FIELD_WIDTH_LEFT_INDEX; j <= FIELD_WIDTH_RIGHT_INDEX; j++) {
            if (field->blocks[i][j] != NULL) {
                delete field->blocks[i][j];
                field->blocks[i][j] = NULL;
            }
        }
        // copy block from upper
        for (int j = i; j > 0; j--) {
            for (int k = FIELD_WIDTH_LEFT_INDEX; k <= FIELD_WIDTH_RIGHT_INDEX; k++) {
                if (field->blocks[j-1][k] != NULL) {
                    field->blocks[j][k] = field->blocks[j-1][k];
                    field->blocks[j-1][k] = NULL;
                }
            }
        }
        deletableLines[i] = false;
    }
}

