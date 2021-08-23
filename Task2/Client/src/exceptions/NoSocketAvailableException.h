//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef CLIENT_NOSOCKETAVAILABLEEXCEPTION_H
#define CLIENT_NOSOCKETAVAILABLEEXCEPTION_H

#include <exception>;

using namespace std;

class NoSocketAvailableException : exception {
public:
    virtual const char *what() const throw() {
        return "Socket unavailable";
    }
};

#endif //CLIENT_NOSOCKETAVAILABLEEXCEPTION_H
