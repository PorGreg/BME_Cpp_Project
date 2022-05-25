//
//  exceptions.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#ifndef exceptions_hpp
#define exceptions_hpp

#include <iostream>
#include <exception>
#include "memtrace.hpp"
using namespace std;

/*
 Exception to handle exit request
 */
struct AppExit : exception {
    const char *what() const throw() {
        return "Exit from application";
    }
};

/*
 Exception to handle wrong input
 */
struct WrongInput : exception {
    const char *what() const throw() {
        return "Wrong input given";
    }
};

/*
 Exception to handle file not found
 */
struct SaveFileNotFound : exception {
    const char *what() const throw() {
        return "Save file not found, need to reset the application!";
    }
};

/*
 Exception to handle unauthorized access
 */
struct WrongAuth : exception {
    const char *what() const throw() {
        return "Invalid username or password";
    }
};


#endif /* exceptions_hpp */
