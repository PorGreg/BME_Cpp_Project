//
//  products.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#ifndef products_hpp
#define products_hpp

#include <iostream>
#include "screen.hpp"
#include "memtrace.hpp"

class Products : public Screen {
public:
    Products(Context &ctx);
    
    void render();
    
    void getInput();
    
    ~Products() {}
};

#endif /* products_hpp */
