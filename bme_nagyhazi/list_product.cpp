//
//  list_product.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#include "list_product.hpp"
#include "utils.hpp"
#include "exceptions.hpp"
#include "memtrace.h"

ListProduct::ListProduct(Context &ctx) : Screen(ctx) {}

void ListProduct::render() {
    cout << "Products" << endl << endl;
    renderProducts();
    cout << endl;
    cout
    << "1: Add product  "
    << "2: Edit product  "
    << "3: Delete product  "
    << "4: Back"
    << endl;
}

void ListProduct::getInput() {
    int choice = Utils::getChoice();
    switch (choice) {
        case 1:
            addProduct();
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

void ListProduct::addProduct() {
    Context *ctx = getCtx();
    ProductType type = ctx->getProductType();
    string productName;
    cout << endl;
    cout << "Name of product: ";
    cin >> productName;
    int releaseYear;
    cout << "Year of release: ";
    cin >> releaseYear;
    double price;
    cout << "Price: ";
    cin >> price;
    if (type == LAPTOP) {
        int cpu, mem, storage;
        cout << "CPU cores: ";
        cin >> cpu;
        cout << "Memory GB: ";
        cin >> mem;
        cout << "Storage GB: ";
        cin >> storage;
        Laptop laptop(productName, releaseYear, price, cpu, mem, storage);
        ctx->getProducts<Laptop>()->add(laptop);
        // cant call template methods, something wrong
//        ctx->addProduct(laptop);
    }
    return;
}
