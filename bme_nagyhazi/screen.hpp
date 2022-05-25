//
//  screen.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#ifndef page_hpp
#define page_hpp

#include <iostream>
#include "context.hpp"
#include "memtrace.h"
using namespace std;

class Screen {
    Context *ctx;
public:
    Screen(Context &ctx);
    
    Context *getCtx();
    
    virtual void render();
    
    virtual void getInput();
    
    ~Screen() {}
};

#endif /* page_hpp */
