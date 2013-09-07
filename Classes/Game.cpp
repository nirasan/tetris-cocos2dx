#include "Game.h"
#include "Config.h"

Game::Game()
{
    field = new Field();
    chunk = new Chunk();
}

Game::~Game()
{
    delete field;
    delete chunk;
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
    if (canMoveUnder())
        chunk->posY = chunk->posY + 1;
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
    for (int i = 0; i < CHUNK_WIDTH; i++) {
        for (int j = CHUNK_HEIGHT - 1; j > 0; j--) {
            if (chunk->blocks[i][j] != NULL) {
                int underY = chunk->posY + j + 1;
                if (underY > FIELD_HEIGHT - 1) return false;
                if (field->blocks[underY][i] != NULL) return false;
                break;
            }
        }
    }
    return true;
}
