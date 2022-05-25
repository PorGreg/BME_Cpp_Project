//
//  logged_home.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 18..
//

#ifndef logged_home_hpp
#define logged_home_hpp

#include <iostream>
#include "screen.hpp"
#include "memtrace.hpp"

class LoggedHome : public Screen {
public:
    LoggedHome(Context &ctx);

    void render();
    
    void getInput();
    
    ~LoggedHome() {}
};

#endif /* logged_home_hpp */
