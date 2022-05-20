//
//  account_settings.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#ifndef account_settings_hpp
#define account_settings_hpp

#include <iostream>
#include "screen.hpp"
#include "context.hpp"
#include "memtrace.hpp"
using namespace std;

class AccountSettings : public Screen {
public:
    AccountSettings(Context &ctx);

    void render();
    
    void getInput();
    
    void changeUsername();
    
    void changePassword();
    
    ~AccountSettings() {}
};

#endif /* account_settings_hpp */
