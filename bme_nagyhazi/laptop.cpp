//
//  laptop.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#include "laptop.hpp"
#include "memtrace.h"

Laptop::Laptop(string name, int year, double price, int cpu, int mem, int storage)
:  Product(name, year, price), cpuCore(cpu), memGB(mem), storageGB(storage) {}

Laptop::Laptop(string name, int year, double price, int cpu, int mem, int storage, unsigned long ID)
:  Product(name, year, price, ID), cpuCore(cpu), memGB(mem), storageGB(storage) {}

const int Laptop::getCpuCore() const {
    return cpuCore;
}
void Laptop::setCpuCore(int &cpu) {
    cpuCore = cpu;
}

const int Laptop::getMemGB() const {
    return memGB;
}
void Laptop::setMemGB(int &mem) {
    memGB = mem;
}

const int Laptop::getStorageGB() const {
    return storageGB;
}
void Laptop::setStorageGB(int &storage) {
    storageGB = storage;
}

const string Laptop::toString() const {
    return Product::toString();
};

ostream &operator<<(ostream& os, const Laptop &laptop) {
    os << laptop.toString();
    return os;
}
