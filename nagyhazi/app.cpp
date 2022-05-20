//
//  screen.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#include <iostream>
#include "app.hpp"
#include "home.hpp"
#include "login.hpp"
#include "register.hpp"
#include "logged_home.hpp"
#include "account_settings.hpp"
#include "products.hpp"
#include "list_product.hpp"
#include "exceptions.hpp"
#include "context.hpp"
#include "memtrace.hpp"
using namespace std;

App::App() : ctx() {
    cout << "App started" << endl;
    while (true) {
        try {
            startCycle();
            ctx.setError("");
        }
        catch (WrongInput &e) {
            ctx.setError(e.what());
        }
        catch (WrongAuth &e) {
            ctx.setError(e.what());
            if (ctx.getLoggedUser() != NULL)
                ctx.navigate(LOGGED_HOME_SCREEN);
            else
                ctx.navigate(HOME_SCREEN);
        }
        catch (AppExit &e) {
            cout << e.what() << endl;
            return;
        }
        catch (exception &e) {
            cout << e.what() << endl;
            return;
        }
    }
}

void App::startCycle() {
    clearScreen();
    
    switch (ctx.getScreen()) {
        case HOME_SCREEN:
            handleScreenChange(new Home(ctx));
            break;
        case LOGIN_SCREEN:
            handleScreenChange(new Login(ctx));
            break;
        case REGISTER_SCREEN:
            handleScreenChange(new Register(ctx));
            break;
        case LOGGED_HOME_SCREEN:
            handleScreenChange(new LoggedHome(ctx));
            break;
        case ACCOUNT_SETTINGS_SCREEN:
            handleScreenChange(new AccountSettings(ctx));
            break;
        case PRODUCTS_SCREEN:
            handleScreenChange(new Products(ctx));
            break;
        case LIST_PRODUCTS_SCREEN:
            handleScreenChange(new ListProduct(ctx));
            break;
        default:
            cout << "Went to unhandled route" << endl;
            throw AppExit();
    }
}

void App::handleScreenChange(Screen *screen) {
    screen->render();
    logError();
    screen->getInput();
    delete screen;
}

void App::logError() {
    string error = ctx.getError();
    if (error.length() > 0)
        cout << "ERROR: " << error << endl;
}

void App::clearScreen() {
    cout << string( 100, '\n' );
}
