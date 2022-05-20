//
//  list_product.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#include "list_product.hpp"
#include "utils.hpp"
#include "exceptions.hpp"
#include "memtrace.hpp"

ListProduct::ListProduct(Context &ctx) : Screen(ctx) {}

void ListProduct::render() {
    cout << "Products" << endl << endl;
    renderProducts();
    cout << endl;
    cout << "1: Add product  "
    << "2: Edit product  "
    << "3: Delete product  "
    << "4: Back"
    << endl;
}

void ListProduct::getInput() {
    int choice = Utils::getChoice();
    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            getCtx()->navigate(PRODUCTS_SCREEN);
            getCtx()->setProductType(UNKNOWN);
            break;
        default:
            throw WrongInput();
    }
}

void ListProduct::renderProducts() {
    Context *ctx = getCtx();
    ProductType type = ctx->getProductType();
    if (type == LAPTOP)
        cout << *ctx->getProducts<Laptop>() << endl;
}
