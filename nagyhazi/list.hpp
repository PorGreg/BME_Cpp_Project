//
//  list.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#ifndef list_hpp
#define list_hpp

#include <iostream>
#include "memtrace.hpp"
using namespace std;

template <typename T, size_t defaultSize = 126>
class List {
    const static size_t sizeMultiplier = 2;
    size_t maxSize = defaultSize, size;
    T **list;
public:
    /*
     Constructor to create a list of the given type
     */
    List() : size(0) {
        list = new T*[maxSize];
    };
    
    /*
     Return the size of the list
     */
    size_t getSize() {
        return size;
    }
    
    /*
     Add the given element to the list.
     Increase the size if there is not enough space.
     */
    void add(T &elem) {
        if (size + 1 > maxSize)
            increaseList();
        list[size++] = new T(elem);
    }
    
    /*
     Extend the given list to this one.
     */
    void extend(List<T> &newList) {
        for (size_t i = 0; i < newList.getSize(); i++)
            add(newList[i]);
    }
    
    /*
     Remove element from list
     */
    void remove(T &elem) {
        bool deleted = false;
        for (size_t i = 0; i < size; i++) {
            if (elem == *list[i]) {
                delete list[i];
                deleted = true;
                continue;
            }
            if (deleted) {
                list[i-1] = list[i];
                if (i-1 == size)
                    list[i] = NULL;
            }
        }
        size -= 1;
    }
    
    /*
     Increase the size of the list.
     Multiple it with a static const variable sizeMultiplier.
     */
    void increaseList() {
        size_t newMaxSize = maxSize * sizeMultiplier;
        T **newList = new T*[newMaxSize];
        for (size_t i = 0; i < size; i++) {
            newList[i] = new T(*list[i]);
        }
        if (maxSize > 0) delete[] list;
        list = newList;
        maxSize = newMaxSize;
    }
    
    const string toString() const {
        string str;
        for (size_t i = 0; i < size; i++) {
            str += list[i]->toString();
        }
        return str;
    }
    
    /*
     Add operators to get element of array;
     */
    T* operator[](size_t idx) { return list[idx]; }
    const T* operator[](size_t idx) const { return list[idx]; }
    
    /*
     Clear list
     */
    void clear() {
        for (size_t i = 0; i < size; i++) {
            delete list[i];
        }
        size = 0;
    }

    ~List() {
        clear();
        delete[] list;
    }
};

template <typename T>
ostream& operator<<(ostream &os, List<T> &list) {
    os << list.toString();
    return os;
}

#endif /* list_hpp */
