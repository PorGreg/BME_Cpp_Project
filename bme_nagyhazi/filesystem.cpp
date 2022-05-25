//
//  filesystem.cpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#include <functional>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "filesystem.hpp"
#include "exceptions.hpp"
#include "memtrace.hpp"
using namespace std;

void FileSystem::readFile(const string &fileName, function<void(string)> func) {
    fstream file = getFile(fileName);
    string line;
    while (getline(file, line)) {
        func(line);
    }
    file.close();
}

void FileSystem::writeFile(const string &fileName, const string &content) {
    fstream file = getFile(fileName, ofstream::out | ofstream::trunc);
    file << content;
    file.close();
}

fstream FileSystem::getFile(const string &fileName, const ios_base::openmode mode) {
    fstream f(fileName.c_str(), mode);
    if (!f.good())
        throw SaveFileNotFound();
    return f;
}
