//
//  product.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#include <iostream>
#include "product.hpp"
#include "memtrace.hpp"
using namespace std;

Product::Product(string name, int year, double price)
: name(name), yearReleased(year), price(price), DbRecord() {}

Product::Product(string name, int year, double price, unsigned long ID)
: name(name), yearReleased(year), price(price), DbRecord(ID) {}

const string Product::getName() const {
    return name;
}
void Product::setName(string &name) {
    name = name;
}

const int Product::getYearReleased() const {
    return yearReleased;
}
void Product::setYearReleased(int &year) {
    yearReleased = year;
}

const double Product::getPrice() const {
    return price;
}
void Product::setPrice(double &price) {
    price = price;
}

const string Product::toString() const {
    return name + ";" + to_string(yearReleased) + ";" + to_string(price) + "\n";
}
