//
//  products.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 19..
//

#include "products.hpp"
#include "utils.hpp"
#include "exceptions.hpp"
#include "memtrace.hpp"

Products::Products(Context &ctx) : Screen(ctx) {}

void Products::render() {
    cout << "Products" << endl << getCtx()->getLoggedUser()->getUsername() << endl << endl;
    cout << "1. Laptops" << endl;
    cout << "2. Computers" << endl;
    cout << "3. Mobiles" << endl;
    cout << "4. Monitors" << endl;
    cout << "5. Back" << endl;
}

void Products::getInput() {
    Context *ctx = getCtx();
    int choice = Utils::getChoice();
    switch (choice) {
        case 1:
            ctx->navigate(LIST_PRODUCTS_SCREEN);
            ctx->setProductType(LAPTOP);
            break;
        case 2:
            ctx->navigate(LIST_PRODUCTS_SCREEN);
            ctx->setProductType(COMPUTER);
            break;
        case 3:
            ctx->navigate(LIST_PRODUCTS_SCREEN);
            ctx->setProductType(MOBILE);
            break;
        case 4:
            ctx->navigate(LIST_PRODUCTS_SCREEN);
            ctx->setProductType(MONITOR);
            break;
        case 5:
            ctx->navigate(LOGGED_HOME_SCREEN);
            break;
        default:
            throw WrongInput();
    }
}
