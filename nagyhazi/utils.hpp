//
//  utils.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#ifndef utils_hpp
#define utils_hpp

#include <iostream>
#include "memtrace.hpp"
using namespace std;

class Utils {
public:
    /*
     Return a list of strings with the given length.
     The returned list is allocated, it needs to be freed after use
     */
    static string *string_tokenize(string str, size_t size, char delimiter = ';');
    
    /*
     Return random long number
     */
    static unsigned long getRandomLong();
    
    /*
     Get only int input from user
     If the input is not an int, throws WrongInput exception
     */
    static int getChoice();
};

#endif /* utils_hpp */
