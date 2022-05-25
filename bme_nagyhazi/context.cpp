//
//  context.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#include <sstream>
#include "context.hpp"
#include "filesystem.hpp"
#include "utils.hpp"
#include "exceptions.hpp"
#include "memtrace.hpp"
using namespace std;

Context::Context() : fileSystem(), users() {
    fileSystem.readFile(USERS_FILE, readUsers(*this));
    fileSystem.readFile(LAPTOP_FILE, readProducts<Laptop>(*this));
}

// ---------------------
// User specific methods
// ---------------------

List<User> &Context::getUsers() {
    return users;
}

User *Context::getUser(string username) {
    for (size_t i = 0; i < users.getSize(); i++) {
        if (users[i]->getUsername() == username)
            return users[i];
    }
    return NULL;
}

void Context::logUserIn(User *user, string password) {
    if (user == NULL || !user->authUser(password))
        throw WrongAuth();
    navigate(LOGGED_HOME_SCREEN);
    loggedUser = user;
    return;
}

void Context::logUserOut() {
    loggedUser = NULL;
    navigate(HOME_SCREEN);
}

User *Context::getLoggedUser() {
    return loggedUser;
}

void Context::addUser(User &user) {
    users.add(user);
    saveUsers();
}

void Context::deleteUser(User &user) {
    if (user == *loggedUser)
        logUserOut();
    users.remove(user);
    saveUsers();
}

void Context::saveUsers() {
    fileSystem.writeFile(USERS_FILE, users.toString());
}

// ------------------------
// Product specific methods
// ------------------------

template <typename T>
List<T> *Context::getProducts() {
    if (is_same<T, Laptop>::value)
        return &laptops;
    return NULL;
}

template <typename T>
T *Context::getProduct(unsigned long ID) {
    List<T> *list = getProducts<T>();
    if (list == NULL)
        return NULL;
    for (size_t i = 0; i < list->getSize(); i++) {
        if (ID == list[i]->getID())
            return list[i];
    }
    return NULL;
}

template <typename T>
void Context::addProduct() {
    List<T> *list = getProducts<T>();
    if (list == NULL)
        return;
    cout << *list << endl;
//    list->add(product);
//    saveProducts<T>();
}

template <typename T>
void Context::deleteProduct(T &product) {
    List<T> *list = getProducts<T>();
    if (list == NULL)
        return;
    list->remove(product);
    saveProducts<T>();
}

template <typename T>
void Context::saveProducts() {
    List<T> *list = getProducts<T>();
    if (list == NULL)
        return;
    fileSystem.writeFile(getSaveFile<T>(), list->toString());
}

template <typename T>
string getSaveFile() {
    if (is_same<T, Laptop>::value)
        return LAPTOP_FILE;
    throw SaveFileNotFound();
}



// --------
// Functors
// --------

Context *Context::contextFunctor::getCtx() {
    return ctx;
}

void Context::readUsers::operator()(string line) {
    string *tempUser = Utils::string_tokenize(line, 3);
    User user(tempUser[1], tempUser[2], stoul(tempUser[0]));
    getCtx()->getUsers().add(user);
}

template <typename T>
void Context::readProducts<T>::operator()(string line) {
    if (is_same<T, Laptop>::value) {
        string *tempLaptop = Utils::string_tokenize(line, 7);
        Laptop laptop(tempLaptop[1],
                      stoi(tempLaptop[2]),
                      stod(tempLaptop[3]),
                      stoi(tempLaptop[4]),
                      stoi(tempLaptop[5]),
                      stoi(tempLaptop[6]),
                      stoul(tempLaptop[0]));
        getCtx()->template getProducts<T>()->add(laptop);
    }
}

// ------------------
// Other util methods
// ------------------

ScreenType &Context::getScreen() {
    return screen;
}

void Context::navigate(ScreenType newScreen) {
    screen = newScreen;
}

ProductType Context::getProductType() {
    return currentProduct;
}
void Context::setProductType(const ProductType &type) {
    currentProduct = type;
}
