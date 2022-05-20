//
//  dbrecord.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 15..
//

#include "utils.hpp"
#include "dbrecord.hpp"
#include "memtrace.hpp"

DbRecord::DbRecord() : ID(Utils::getRandomLong()) {}

DbRecord::DbRecord(unsigned long ID) : ID(ID) {}

string DbRecord::toString() {
    return to_string(ID);
}

const unsigned long DbRecord::getID() const {
    return ID;
}

bool DbRecord::operator==(DbRecord &dbc) {
    return dbc.getID() == getID();
}
