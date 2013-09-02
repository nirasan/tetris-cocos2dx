#ifndef __tetris__Block__
#define __tetris__Block__

#include <iostream>

class Block
{
private:
    
    int color;
    
public:
    
    enum kColor {
        kColor_White,
    };
    
    Block();
    ~Block();
    
    int getColor();
};

#endif /* defined(__tetris__Block__) */
