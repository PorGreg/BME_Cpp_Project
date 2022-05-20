//
//  context.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#ifndef context_hpp
#define context_hpp

#include <iostream>
#include "filesystem.hpp"
#include "user.hpp"
#include "laptop.hpp"
#include "list.hpp"
#include "product.hpp"
#include "memtrace.hpp"
using namespace std;

const string USERS_FILE = "users.txt";
const string LAPTOP_FILE = "laptops.txt";
const string COMPUTER_FILE = "computers.txt";
const string MOBILE_FILE = "mobiles.txt";
const string MONITOR_FILE = "monitors.txt";

enum ScreenType {
    HOME_SCREEN,
    LOGIN_SCREEN,
    REGISTER_SCREEN,
    LOGGED_HOME_SCREEN,
    PRODUCTS_SCREEN,
    ACCOUNT_SETTINGS_SCREEN,
    LIST_PRODUCTS_SCREEN
};

class Context {
    FileSystem fileSystem;
    ScreenType screen = HOME_SCREEN;
    User *loggedUser = NULL;
    List<User> users;
    List<Laptop> laptops;
    ProductType currentProduct = UNKNOWN;
    string error = "";
public:
    Context();
    
    // ---------------------
    // User specific methods
    // ---------------------
    
    /*
     Get list of users
     */
    List<User> &getUsers();
    
    /*
     Get user from the user list
     */
    User *getUser(string username);
    
    /*
     Log in the given user
     */
    void logUserIn(User *user, string password);
    
    /*
     Log out the user
     */
    void logUserOut();
    
    /*
     Return logged user
     */
    User *getLoggedUser();
    
    /*
     Add and save a user to the list
     */
    void addUser(User &user);
    
    /*
     Delete user
     */
    void deleteUser(User &user);
    
    /*
     Save user data
     */
    void saveUsers();
    
    // ------------------------
    // Product specific methods
    // ------------------------
    
    template <typename T>
    List<T> *getProducts();
    
    template <typename T>
    T *getProduct(unsigned long ID);
    
    template <typename T>
    void addProduct(T &product);
    
    template <typename T>
    void deleteProduct(T &product);
    
    /*
     Save products data
     */
    template <typename T>
    void saveProducts();
    
    template <typename T>
    static string getSaveFile();
    
    // --------
    // Functors
    // --------
    
    /*
     Base class for state functors
     */
    class contextFunctor {
        Context *ctx;
    public:
        contextFunctor(Context &ctx) : ctx(&ctx) {}
        Context *getCtx();
    };
    
    /*
     Reader functors to read data from string line.
     These functors are using FileSystem::readFile(std::string)
     */
    class readUsers : public contextFunctor {
    public:
        readUsers(Context &ctx) : contextFunctor(ctx) {}
        void operator()(string line);
    };
    template <typename T>
    class readProducts : public contextFunctor {
    public:
        readProducts(Context &ctx) : contextFunctor(ctx) {}
        void operator()(string line);
    };
    
    // ------------------
    // Other util methods
    // ------------------
    
    // Get current screen
    ScreenType &getScreen();
    
    // navigate screen
    void navigate(ScreenType newScreen);
    
    // error handling
    void setError(string err) { error = err; }
    string getError() { return error; }
    
    /*
     Get and set current product type
     */
    ProductType getProductType();
    void setProductType(const ProductType &type);
    
    ~Context() {}
};

#endif /* context_hpp */
