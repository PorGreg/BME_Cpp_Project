//
//  laptop.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#ifndef laptop_hpp
#define laptop_hpp

#include <iostream>
#include "product.hpp"
#include "memtrace.h"

class Laptop : public Product {
    int cpuCore, memGB, storageGB;
public:
    Laptop(string name, int year, double price, int cpu, int mem, int storage);
    Laptop(string name, int year, double price, int cpu, int mem, int storage, unsigned long ID);

    /*
     Get and set cpuCore
     */
    const int getCpuCore() const;
    void setCpuCore(int &cpu);
    
    /*
     Get and set memGB
     */
    const int getMemGB() const;
    void setMemGB(int &mem);
    
    /*
     Get and set storageGB
     */
    const int getStorageGB() const;
    void setStorageGB(int &storage);
    
    const string toString() const;
    
    ~Laptop() {};
};

ostream &operator<<(ostream& os, const Laptop &laptop);

#endif /* laptop_hpp */
