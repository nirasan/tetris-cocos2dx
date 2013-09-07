#import "ChunkTest.h"
#import "Block.h"
#import "Chunk.h"

@implementation ChunkTest

- (void)testChunk {
    
    Chunk* c1 = new Chunk();
    Chunk::makeBlocks(c1->blocks, Chunk::kShape_o);
    auto b1 = c1->blocks;
    
    STAssertTrue(b1[0][0] == NULL, @"");
    STAssertTrue(b1[0][1] == NULL, @"");
    STAssertTrue(b1[0][2] == NULL, @"");
    STAssertTrue(b1[0][3] == NULL, @"");
    STAssertTrue(b1[1][0] == NULL, @"");
    STAssertTrue(b1[1][1] != NULL, @"");
    STAssertTrue(b1[1][2] != NULL, @"");
    STAssertTrue(b1[1][3] == NULL, @"");
    STAssertTrue(b1[2][0] == NULL, @"");
    STAssertTrue(b1[2][1] != NULL, @"");
    STAssertTrue(b1[2][2] != NULL, @"");
    STAssertTrue(b1[2][3] == NULL, @"");
    STAssertTrue(b1[3][0] == NULL, @"");
    STAssertTrue(b1[3][1] == NULL, @"");
    STAssertTrue(b1[3][2] == NULL, @"");
    STAssertTrue(b1[3][3] == NULL, @"");
    
    STAssertTrue(b1[1][1]->getColor() == Block::kColor_White, @"");
    
    delete b1;
    
    Chunk* c2 = new Chunk();
    Chunk::makeBlocks(c2->blocks, Chunk::kShape_i);
    auto b2 = c2->blocks;
    
    STAssertTrue(b2[0][0] == NULL, @"");
    STAssertTrue(b2[0][1] != NULL, @"");
    STAssertTrue(b2[0][2] == NULL, @"");
    STAssertTrue(b2[0][3] == NULL, @"");
    STAssertTrue(b2[1][0] == NULL, @"");
    STAssertTrue(b2[1][1] != NULL, @"");
    STAssertTrue(b2[1][2] == NULL, @"");
    STAssertTrue(b2[1][3] == NULL, @"");
    STAssertTrue(b2[2][0] == NULL, @"");
    STAssertTrue(b2[2][1] != NULL, @"");
    STAssertTrue(b2[2][2] == NULL, @"");
    STAssertTrue(b2[2][3] == NULL, @"");
    STAssertTrue(b2[3][0] == NULL, @"");
    STAssertTrue(b2[3][1] != NULL, @"");
    STAssertTrue(b2[3][2] == NULL, @"");
    STAssertTrue(b2[3][3] == NULL, @"");
    
    STAssertTrue(b2[0][1]->getColor() == Block::kColor_White, @"");
    
    delete b2;
    
    //STFail(@"test test test");
}

- (void)testMakeTurnedLeftBlocks {
    
    Chunk* c1 = new Chunk();
    Chunk::makeBlocks(c1->blocks, Chunk::kShape_i);
    auto b1 = c1->blocks;
    
    STAssertTrue(b1[0][0] == NULL, @"");
    STAssertTrue(b1[0][1] != NULL, @"");
    STAssertTrue(b1[0][2] == NULL, @"");
    STAssertTrue(b1[0][3] == NULL, @"");
    STAssertTrue(b1[1][0] == NULL, @"");
    STAssertTrue(b1[1][1] != NULL, @"");
    STAssertTrue(b1[1][2] == NULL, @"");
    STAssertTrue(b1[1][3] == NULL, @"");
    STAssertTrue(b1[2][0] == NULL, @"");
    STAssertTrue(b1[2][1] != NULL, @"");
    STAssertTrue(b1[2][2] == NULL, @"");
    STAssertTrue(b1[2][3] == NULL, @"");
    STAssertTrue(b1[3][0] == NULL, @"");
    STAssertTrue(b1[3][1] != NULL, @"");
    STAssertTrue(b1[3][2] == NULL, @"");
    STAssertTrue(b1[3][3] == NULL, @"");
    
    Block*** b2 = c1->makeTurnedLeftBlocks();
    
    STAssertTrue(b2[0][0] == NULL, @"");
    STAssertTrue(b2[0][1] == NULL, @"");
    STAssertTrue(b2[0][2] == NULL, @"");
    STAssertTrue(b2[0][3] == NULL, @"");
    STAssertTrue(b2[1][0] == NULL, @"");
    STAssertTrue(b2[1][1] == NULL, @"");
    STAssertTrue(b2[1][2] == NULL, @"");
    STAssertTrue(b2[1][3] == NULL, @"");
    STAssertTrue(b2[2][0] != NULL, @"");
    STAssertTrue(b2[2][1] != NULL, @"");
    STAssertTrue(b2[2][2] != NULL, @"");
    STAssertTrue(b2[2][3] != NULL, @"");
    STAssertTrue(b2[3][0] == NULL, @"");
    STAssertTrue(b2[3][1] == NULL, @"");
    STAssertTrue(b2[3][2] == NULL, @"");
    STAssertTrue(b2[3][3] == NULL, @"");
    
    //STAssertTrue(b2[1][0]->getColor() == Block::kColor_White, @"");
    
    //STFail(@"test test test");
}

- (void)testMakeTurnedRightBlocks {
    
    Chunk* c1 = new Chunk();
    Chunk::makeBlocks(c1->blocks, Chunk::kShape_i);
    auto b1 = c1->blocks;
    
    STAssertTrue(b1[0][0] == NULL, @"");
    STAssertTrue(b1[0][1] != NULL, @"");
    STAssertTrue(b1[0][2] == NULL, @"");
    STAssertTrue(b1[0][3] == NULL, @"");
    STAssertTrue(b1[1][0] == NULL, @"");
    STAssertTrue(b1[1][1] != NULL, @"");
    STAssertTrue(b1[1][2] == NULL, @"");
    STAssertTrue(b1[1][3] == NULL, @"");
    STAssertTrue(b1[2][0] == NULL, @"");
    STAssertTrue(b1[2][1] != NULL, @"");
    STAssertTrue(b1[2][2] == NULL, @"");
    STAssertTrue(b1[2][3] == NULL, @"");
    STAssertTrue(b1[3][0] == NULL, @"");
    STAssertTrue(b1[3][1] != NULL, @"");
    STAssertTrue(b1[3][2] == NULL, @"");
    STAssertTrue(b1[3][3] == NULL, @"");
    
    Block*** b2 = c1->makeTurnedRightBlocks();
    
    STAssertTrue(b2[0][0] == NULL, @"");
    STAssertTrue(b2[0][1] == NULL, @"");
    STAssertTrue(b2[0][2] == NULL, @"");
    STAssertTrue(b2[0][3] == NULL, @"");
    STAssertTrue(b2[1][0] != NULL, @"");
    STAssertTrue(b2[1][1] != NULL, @"");
    STAssertTrue(b2[1][2] != NULL, @"");
    STAssertTrue(b2[1][3] != NULL, @"");
    STAssertTrue(b2[2][0] == NULL, @"");
    STAssertTrue(b2[2][1] == NULL, @"");
    STAssertTrue(b2[2][2] == NULL, @"");
    STAssertTrue(b2[2][3] == NULL, @"");
    STAssertTrue(b2[3][0] == NULL, @"");
    STAssertTrue(b2[3][1] == NULL, @"");
    STAssertTrue(b2[3][2] == NULL, @"");
    STAssertTrue(b2[3][3] == NULL, @"");
    
    //STAssertTrue(b2[1][0]->getColor() == Block::kColor_White, @"");
    
    //STFail(@"test test test");
}

- (void)testUpdateBlocks {
    
    Chunk* c1 = new Chunk();
    Chunk::makeBlocks(c1->blocks, Chunk::kShape_i);
    Block*** blocks1 = c1->makeTurnedLeftBlocks();
    Block* block1 = blocks1[2][0];
    
    STAssertTrue(c1->blocks[0][1] != NULL, @"");
    STAssertTrue(blocks1[2][0] != NULL, @"");
    STAssertTrue(c1->blocks[0][1] == block1, @"");

    c1->updateBlocks(blocks1);
    
    STAssertTrue(c1->blocks[0][1] == NULL, @"");
    STAssertTrue(c1->blocks[2][0] != NULL, @"");
    STAssertTrue(c1->blocks[2][0] == block1, @"");
}

@end
