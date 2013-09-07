#import "GameTest.h"
#import "Game.h"
#import "Chunk.h"
#import "Field.h"
#import "Block.h"

@implementation GameTest

- (void)testGame {
    Game* game = new Game();
    STAssertTrue(game != NULL, @"");
}

- (void)testMoveLeft {
    Game* game = new Game();
    Chunk::makeBlocks(game->chunk->blocks, Chunk::kShape_o);
    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX, 0);
    
    STAssertTrue(game->canMoveLeft(), @"左に余裕あるので真");
    
    game->moveLeft();
    STAssertTrue(game->chunk->posX == FIELD_WIDTH_LEFT_INDEX - 1, @"一番左の列");
    STAssertTrue(!game->canMoveLeft(), @"左に余裕無いので偽");
}

- (void)testMoveRight {
    Game* game = new Game();
    Chunk::makeBlocks(game->chunk->blocks, Chunk::kShape_o);
    game->chunk->setPos(FIELD_WIDTH_RIGHT_INDEX - (CHUNK_WIDTH - 1), 0);
    
    STAssertTrue(game->canMoveRight(), @"右に１列余裕あるので真");
    
    game->moveRight();
    STAssertTrue(game->chunk->posX == FIELD_WIDTH_RIGHT_INDEX - (CHUNK_WIDTH - 1) + 1, @"一番右の列");
    STAssertTrue(!game->canMoveRight(), @"右に余裕無いので偽");
}

- (void)testMoveUnder {
    Game* game = new Game();
    Chunk::makeBlocks(game->chunk->blocks, Chunk::kShape_o);
    game->chunk->setPos(0, (FIELD_HEIGHT - 1) - (CHUNK_HEIGHT - 1));
    
    STAssertTrue(game->canMoveUnder(), @"下に1行余裕あるので真");
    STAssertTrue(game->chunk->blocks[1][1]->getNumber() == 0, @"block[1][1] 's id = %d", game->chunk->blocks[1][1]->getNumber());
    
    game->moveUnder();
    STAssertTrue(game->chunk->posY == (FIELD_HEIGHT - 1) - (CHUNK_HEIGHT - 1) + 1, @"一番下の列");
    STAssertTrue(!game->canMoveUnder(), @"下に余裕無いので偽");
}

@end
