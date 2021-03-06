//
//  user.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 14..
//

#include <iostream>
#include "user.hpp"
#include "memtrace.h"
using namespace std;

User::User(string username, string password)
: DbRecord(), username(username), password(password)  {}

User::User(string username, string password, unsigned long ID)
: DbRecord(ID), username(username), password(password) {}

User::User(User &user)
: User(user.username, user.password, user.getID()) {}

const string User::getUsername() const {
    return username;
}

void User::setUsername(string newUsername) {
    username = newUsername;
}

bool User::authUser(string pwd) {
    return password == pwd;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

const string User::toString() const {
    return to_string(getID()) + ";" + username + ";" + password + "\n";
}

bool User::operator==(User &user) {
    return user.username == username && user.password == password && user.getID() == getID();
}

ostream &operator<<(ostream &os, const User &user) {
    os << user.toString();
    return os;
}
