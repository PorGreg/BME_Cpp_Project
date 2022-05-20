//
//  register.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#include <iostream>
#include "register.hpp"
#include "exceptions.hpp"
#include "memtrace.hpp"
using namespace std;

Register::Register(Context &ctx) : Screen(ctx) {};

void Register::render() {
    Context *ctx = getCtx();
    string username, password, password2;
    bool usernameUnique = false, passwordsMatch = false;
    cout << "Register" << endl << endl;
    while (!usernameUnique) {
        cout << "Username: ";
        cin >> username;
        User *existing = ctx->getUser(username);
        if (existing != NULL)
            cout << "User with this name already exists!" << endl;
        else
            usernameUnique = true;
    }
    while (!passwordsMatch) {
        cout << "Password: ";
        cin >> password;
        cout << "Password again: ";
        cin >> password2;
        passwordsMatch = password == password2;
        if (!passwordsMatch)
            cout << "The passwords does not match!" << endl;
    }
    User newUser(username, password);
    ctx->addUser(newUser);
    ctx->navigate(HOME_SCREEN);
}

void Register::getInput() {};

