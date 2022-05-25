//
//  product.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#ifndef product_hpp
#define product_hpp

#include <iostream>
#include "dbrecord.hpp"
#include "memtrace.h"
using namespace std;

enum ProductType { LAPTOP, COMPUTER, MOBILE, MONITOR, UNKNOWN };

class Product : public DbRecord {
    string name;
    int yearReleased;
    double price;
public:
    Product(string nam, int year, double pric);
    Product(string nam, int year, double pric, unsigned long ID);
    
    /*
     Get and set name of product
     */
    const string getName() const;
    void setName(string &nam);
    
    /*
     Get and set release year
     */
    const int getYearReleased() const;
    void setYearReleased(int &year);
    
    /*
     Get and set prive
     */
    const double getPrice() const;
    void setPrice(double &pric);
    
    /*
     Parse to string
     */
    virtual const string toString() const;
    
    virtual ~Product() {};
};

#endif /* product_hpp */
