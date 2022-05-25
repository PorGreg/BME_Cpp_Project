//
//  home.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#ifndef home_hpp
#define home_hpp

#include <iostream>
#include "screen.hpp"
#include "context.hpp"
#include "memtrace.h"

class Home : public Screen {
public:
    Home(Context &ctx);

    void render();
    
    void getInput();
    
    ~Home() {}
};

#endif /* home_hpp */
