//
//  filesystem.hpp
//  nagyhazi
//
//  Created by Gergo Por on 2022. 05. 12..
//

#ifndef filesystem_hpp
#define filesystem_hpp

#include <functional>
#include <fstream>
#include <iostream>
#include "memtrace.hpp"
using namespace std;

class FileSystem {
    string root;
public:
    /*
     Base constructor, initialize root with the current directory
     */
    FileSystem() : root(filesystem::current_path()) {}
    
    /*
     Read the given file and execute the given function with every line
     */
    void readFile(const string &fileName, function<void(string)> func);
    
    /*
     Create a file with the given name
     Returning true/false based on success
     */
    void writeFile(const string &fileName, const string &content);
    
    /*
     Delete a file with the given name
     Returning true/false based on success
     */
    bool deleteFile(const string &fileName);
    
    /*
     Get the given file
     */
    fstream getFile(const string &fileName,
                    const ios_base::openmode mode = ios_base::in | ios_base::out);
    
    /*
     Return the root
     */
    string getRoot() {
        return root + "/";
    }
    
    /*
     Simple destructor
     */
    ~FileSystem() {}
};

#endif /* filesystem_hpp */
