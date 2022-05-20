//
//  account_settings.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#include "account_settings.hpp"
#include "exceptions.hpp"
#include "utils.hpp"
#include "memtrace.hpp"

AccountSettings::AccountSettings(Context &ctx) : Screen(ctx) {}

void AccountSettings::render() {
    cout << "Account settings" << endl << getCtx()->getLoggedUser()->getUsername() << endl << endl;
    cout << "1: Change username" << endl;
    cout << "2: Change password" << endl;
    cout << "3: Delete account" << endl;
    cout << "4: Back" << endl;
}

void AccountSettings::getInput() {
    Context *ctx = getCtx();
    int choice = Utils::getChoice();
    switch (choice) {
        case 1:
            changeUsername();
            break;
        case 2:
            changePassword();
            break;
        case 3:
            ctx->deleteUser(*ctx->getLoggedUser());
            break;
        case 4:
            ctx->navigate(LOGGED_HOME_SCREEN);
            break;
        default:
            throw WrongInput();
    }
}

void AccountSettings::changeUsername() {
    Context *ctx = getCtx();
    User *loggedUser = ctx->getLoggedUser();
    string username;
    bool usernameUnique = false;
    while (!usernameUnique) {
        cout << endl << "Username: ";
        cin >> username;
        User *user = ctx->getUser(username);
        if (user == NULL || username == loggedUser->getUsername())
            usernameUnique = true;
        else
            cout << "Username is already in use!" << endl;
    }
    loggedUser->setUsername(username);
    ctx->saveUsers();
}

void AccountSettings::changePassword() {
    Context *ctx = getCtx();
    User *loggedUser = ctx->getLoggedUser();
    string password;
    cout << endl << "Password: ";
    cin >> password;
    loggedUser->setPassword(password);
    ctx->saveUsers();
}
