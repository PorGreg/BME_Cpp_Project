//
//  dbrecord.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#ifndef dbrecord_hpp
#define dbrecord_hpp

#include <iostream>
#include "memtrace.h"
using namespace std;

class DbRecord {
    const unsigned long ID;
public:
    DbRecord();
    
    DbRecord(unsigned long ID);
    
    const unsigned long getID() const;
    
    virtual const string toString() const;
    
    virtual bool operator==(DbRecord &dbc);
    
    ~DbRecord() {}
};

#endif /* dbrecord_hpp */
