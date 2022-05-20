//
//  utils.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "utils.hpp"
#include "exceptions.hpp"
#include "memtrace.hpp"
using namespace std;

string *Utils::string_tokenize(string str, size_t size, char delimiter) {
    stringstream ss(str);
    string temp;
    string *stringList = new string[size];
    size_t idx = 0;
    
    while (getline(ss, temp, delimiter) && idx < size)
        stringList[idx++] = temp;
    
    return stringList;
}

// src: https://stackoverflow.com/questions/3665257/generate-random-long-number
unsigned long Utils::getRandomLong() {
    srand(time(NULL));
    if (sizeof(int) < sizeof(long))
        return (static_cast<long>(rand()) << (sizeof(int) * 8)) |
        rand();
    
    return rand();
}

// src: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
int Utils::getChoice() {
    int x = 0;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw WrongInput();
    }
    return x;
}
