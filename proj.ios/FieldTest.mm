#import "FieldTest.h"
#import "Field.h"
#import "Block.h"

@implementation FieldTest

- (void)testField {
    Field* f = new Field();
    f->blocks[1][1] = new Block(0, Block::kColor_White);
    STAssertTrue(f->blocks[1][1]->getNumber() == 0, @"");
}

@end
