#import "GameTest.h"
#import "Game.h"
#import "Chunk.h"
#import "Field.h"

@implementation GameTest

- (void)testGame {
    Game* game = new Game();
    STAssertTrue(game != NULL, @"");
}

- (void)testMoveLeft {
    Game* game = new Game();
    Chunk::makeBlocks(game->chunk->blocks, Chunk::kShape_i);
    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX, 0);
    
    STAssertTrue(game->canMoveLeft(), @"");
    
    game->moveLeft();
    STAssertTrue(!game->canMoveLeft(), @"");
}

@end
