#ifndef __tetris__Block__
#define __tetris__Block__

#include <iostream>

class Block
{
private:
    
    int number;
    int color;
    
public:
    
    enum kColor {
        kColor_White,
    };
    
    Block(int number, int color);
    ~Block();
    
    int getNumber();
    int getColor();
};

#endif /* defined(__tetris__Block__) */
