//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_COULDNOTBINDPORTEXCEPTION_H
#define SERVER_COULDNOTBINDPORTEXCEPTION_H

#include <exception>

using namespace std;

class CouldNotBindPortException : exception {
public:
    virtual const char *what() const throw() {
        return "Could not bind port";
    }
};

#endif //SERVER_COULDNOTBINDPORTEXCEPTION_H
