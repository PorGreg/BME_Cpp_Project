//
//  list_product.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#ifndef list_product_hpp
#define list_product_hpp

#include <iostream>
#include "screen.hpp"
#include "memtrace.h"

class ListProduct : public Screen {
public:
    ListProduct(Context &ctx);
    
    void render();
    
    void getInput();
    
    void renderProducts();
    
    void addProduct();
    
    ~ListProduct() {};
};

#endif /* list_product_hpp */
