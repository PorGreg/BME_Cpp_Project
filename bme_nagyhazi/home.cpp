//
//  home.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#include <iostream>
#include "home.hpp"
#include "exceptions.hpp"
#include "utils.hpp"
#include "memtrace.h"
using namespace std;

Home::Home(Context &ctx) : Screen(ctx) {}

void Home::render() {
    cout
    << "Welcome!" << endl
    << endl
    << "1: Login" << endl
    << "2: Register" << endl
    << "3: Exit" << endl;
}

void Home::getInput() {
    int choice = Utils::getChoice();
    switch (choice) {
        case 1:
            getCtx()->navigate(LOGIN_SCREEN);
            break;
        case 2:
            getCtx()->navigate(REGISTER_SCREEN);
            break;
        case 3:
            throw AppExit();
        default:
            throw WrongInput();
    }
}
