//
//  user.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 14..
//

#ifndef user_hpp
#define user_hpp

#include <iostream>
#include "dbrecord.hpp"
#include "memtrace.hpp"
using namespace std;

class User : public DbRecord {
    string username, password;
public:
    User(string username, string password);
    
    User(string username, string password, unsigned long ID);
    
    User(User &user);
    
    const string getUsername() const;
    
    void setUsername(string newUsername);
    
    bool authUser(string pwd);
    
    void setPassword(string newPassword);
    
    const string toString() const;
    
    bool operator==(User &user);
    
    virtual ~User() {}
};

ostream &operator<<(ostream &os, const User &user);

#endif /* user_hpp */
