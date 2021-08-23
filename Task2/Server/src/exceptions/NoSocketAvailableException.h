//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_NOSOCKETAVAILABLEEXCEPTION_H
#define SERVER_NOSOCKETAVAILABLEEXCEPTION_H

#include <exception>

using namespace std;

class NoSocketAvailableException : exception {
public:
    virtual const char *what() const throw() {
        return "Socket unavailable";
    }
};

#endif //SERVER_NOSOCKETAVAILABLEEXCEPTION_H
