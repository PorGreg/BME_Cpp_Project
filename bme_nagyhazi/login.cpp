//
//  login.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#include <iostream>
#include "login.hpp"
#include "exceptions.hpp"
#include "memtrace.h"
using namespace std;

Login::Login(Context &ctx) : Screen(ctx) {}

void Login::render() {
    Context *ctx = getCtx();
    string username, password;
    cout << "Login" << endl << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    ctx->logUserIn(ctx->getUser(username), password);
}

void Login::getInput() {}

