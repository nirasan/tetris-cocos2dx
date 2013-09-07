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

