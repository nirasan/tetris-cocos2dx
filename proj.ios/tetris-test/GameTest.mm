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
    
    STAssertTrue(game->chunk->blocks[1][1] == NULL, @"");
    STAssertTrue(game->field->blocks[22][1]->getNumber() == 0, @"block[22][1] 's id = %d", game->field->blocks[22][1]->getNumber());
    STAssertTrue(game->field->blocks[22][1] != NULL, @"");
    STAssertTrue(game->field->blocks[22][2] != NULL, @"");
    STAssertTrue(game->field->blocks[23][1] != NULL, @"");
    STAssertTrue(game->field->blocks[23][2] != NULL, @"");
    
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            //STAssertTrue(game->field->blocks[i][j] == NULL, @"===== x:%d y:%d =====", j, i);
        }
    }
    /*
     NSLog(@"number is %d", game->field->blocks[22][1]->getNumber());
     NSLog(@"number is %d", game->field->blocks[22][2]->getNumber());
     NSLog(@"number is %d", game->field->blocks[23][1]->getNumber());
     NSLog(@"number is %d", game->field->blocks[23][2]->getNumber());
     */
}

- (void)testConflict {
    Game* game = new Game();
    Chunk::makeBlocks(game->chunk->blocks, Chunk::kShape_i); // 0,1 : 1,1 : 2,1 : 3,1
    
    game->chunk->setPos(0, 0);
    STAssertTrue(game->isConflict(), @"画面外なので真（左側境界）");
    
    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX, 0);
    STAssertTrue(!game->isConflict(), @"画面内なので偽");
    
    game->turnLeft(); // 2,0 : 2,1 : 2,2 : 2,3
    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX, 0);
    STAssertTrue(!game->isConflict(), @"画面内なので偽");
    
    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX-1, 0);
    STAssertTrue(game->isConflict(), @"画面外なので真（左側境界）");
    
    game->chunk->setPos(FIELD_WIDTH_RIGHT_INDEX, 0);
    STAssertTrue(game->isConflict(), @"画面外なので真（右側境界）");
    
    game->chunk->setPos(FIELD_WIDTH_RIGHT_INDEX-2, 0);
    game->turnLeft(); // 0,2 : 1,2 : 2,2 : 3,2
    STAssertTrue(!game->isConflict(), @"画面内なので偽");
    
    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX, FIELD_HEIGHT-CHUNK_HEIGHT);
    STAssertTrue(!game->isConflict(), @"画面内なので偽（下側境界）");

    game->chunk->setPos(FIELD_WIDTH_LEFT_INDEX, FIELD_HEIGHT-CHUNK_HEIGHT+1);
    STAssertTrue(game->isConflict(), @"画面外なので真（下側境界）");
}

- (void)testDelete {
    Game* game = new Game();
    
    for (int i = FIELD_WIDTH_LEFT_INDEX; i <= FIELD_WIDTH_RIGHT_INDEX; i++) {
        if (i % 2 == 0) game->field->blocks[5][i] = new Block(50 + i, Block::kColor_White);
        game->field->blocks[10][i] = new Block(100 + i, Block::kColor_White);
        if (i % 2 == 0) game->field->blocks[15][i] = new Block(150 + i, Block::kColor_White);
        game->field->blocks[20][i] = new Block(200 + i, Block::kColor_White);
    }
    
    game->checkDeletableLines();
    
    STAssertTrue(game->deletableLines[5]  == false, @"");
    STAssertTrue(game->deletableLines[10] == true, @"");
    STAssertTrue(game->deletableLines[15] == false, @"");
    STAssertTrue(game->deletableLines[20] == true, @"");
    
    game->deleteDeletableLines();
    
    STAssertTrue(game->deletableLines[5]  == false, @"");
    STAssertTrue(game->deletableLines[10] == false, @"");
    STAssertTrue(game->deletableLines[15] == false, @"");
    STAssertTrue(game->deletableLines[20] == false, @"");
    
    STAssertTrue(game->field->blocks[7][4]  != NULL, @"2段落ちた");
    STAssertTrue(game->field->blocks[16][4] != NULL, @"1段落ちた");
    
    /*
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            STAssertTrue(game->field->blocks[i][j] == NULL, @"[testDelete] x:%d y:%d is not NULL", j, i);
        }
    }
     */
}

@end
