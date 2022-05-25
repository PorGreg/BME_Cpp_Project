//
//  logged_home.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 18..
//

#include "logged_home.hpp"
#include "exceptions.hpp"
#include "utils.hpp"
#include "memtrace.h"

LoggedHome::LoggedHome(Context &ctx) : Screen(ctx) {}

void LoggedHome::render() {
    cout << "Welcome!" << endl << getCtx()->getLoggedUser()->getUsername() << endl << endl;
    cout << "1: View products" << endl;
    cout << "2: Account settings" << endl;
    cout << "3: Log out" << endl;
}

void LoggedHome::getInput() {
    int choice = Utils::getChoice();
    switch (choice) {
        case 1:
            getCtx()->navigate(PRODUCTS_SCREEN);
            break;
        case 2:
            getCtx()->navigate(ACCOUNT_SETTINGS_SCREEN);
            break;
        case 3:
            getCtx()->logUserOut();
            break;
        default:
            throw WrongInput();
    }
}
