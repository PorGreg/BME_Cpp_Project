//
//  screen.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 18..
//

#include <iostream>
#include "screen.hpp"
#include "memtrace.h"

Screen::Screen(Context &ctx) : ctx(&ctx) {};

Context *Screen::getCtx()  {
    return ctx;
}

void Screen::render() {
    cout << "Base page" << endl;
}

void Screen::getInput() {}
