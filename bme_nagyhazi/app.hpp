//
//  screen.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#ifndef app_hpp
#define app_hpp

#include <iostream>
#include "screen.hpp"
#include "context.hpp"
#include "memtrace.hpp"
using namespace std;

class App {
    Context ctx;
public:
    /*
     Constructor for the application
     Starts everything
     */
    App();
    
    /*
     Handles the change of the screen.
     Invoking the render, getInput and logError methods.
     */
    template <typename T>
    void handleScreenChange();
    
    /*
     Log the current error message
     */
    void logError();
    
    /*
     Starts the cycle of the app:
     render -> input -> handle input -> render -> input -> etc.
     */
    void startCycle();
    
    /*
     Clear the screen
     */
    void clearScreen();
    
    /*
     Simple destructor
     */
    ~App() {}
};

#endif /* screen_hpp */
