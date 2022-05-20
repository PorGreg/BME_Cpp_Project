//
//  login.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#ifndef login_hpp
#define login_hpp

#include <iostream>
#include "screen.hpp"
#include "context.hpp"
#include "memtrace.hpp"
using namespace std;

class Login : public Screen {
public:
    Login(Context &ctx);

    void render();
    
    void getInput();
    
    ~Login() {}
};

#endif /* login_hpp */
