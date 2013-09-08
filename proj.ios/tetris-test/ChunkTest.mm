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

- (void)testTurnLeft {
    
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
    
    c1->turnLeft();
    Block*** b2 = c1->blocks;
    
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

- (void)testTurnRight {
    
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
    
    c1->turnRight();
    Block*** b2 = c1->blocks;
    
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

@end
