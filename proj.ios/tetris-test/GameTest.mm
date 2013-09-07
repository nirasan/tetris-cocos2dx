#import "GameTest.h"
#import "Game.h"

@implementation GameTest

- (void)testGame {
    Game* game = new Game();
    STAssertTrue(game != NULL, @"");
}

@end
