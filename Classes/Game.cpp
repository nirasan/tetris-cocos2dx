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
    for (int i = chunk->posY; i < chunk->posY + CHUNK_HEIGHT; i++) {
        for (int j = chunk->posX; j < chunk->posX + CHUNK_WIDTH; j++) {
            if (chunk->blocks[i][j] != NULL) {
                int leftX = j - 1;
                if (leftX < 0) return false;
                if (field->blocks[i][leftX] != NULL) return false;
                break;                
            }
        }
    }
    return true;
}

