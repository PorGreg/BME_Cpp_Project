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

Product::Product(string nam, int year, double pric)
: name(nam), yearReleased(year), price(pric), DbRecord() {}

Product::Product(string nam, int year, double pric, unsigned long ID)
: name(nam), yearReleased(year), price(pric), DbRecord(ID) {}

const string Product::getName() const {
    return name;
}
void Product::setName(string &nam) {
    name = nam;
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
void Product::setPrice(double &pric) {
    price = pric;
}

const string Product::toString() const {
    return name + ";" + to_string(yearReleased) + ";" + to_string(price) + "\n";
}
