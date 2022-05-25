//
//  register.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#ifndef register_hpp
#define register_hpp

#include <iostream>
#include "screen.hpp"
#include "context.hpp"
#include "memtrace.hpp"
using namespace std;

class Register : public Screen {
public:
    Register(Context &ctx);

    void render();
    
    void getInput();
    
    ~Register() {}
};

#endif /* register_hpp */
