//
//  main.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#include <iostream>
#include "app.hpp"
#include "memtrace.h"

int main(int argc, const char * argv[]) {
    try {
        App app;
        return 0;
    }
    catch (std::exception &e) {
        return 0;
    }
}
