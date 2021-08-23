//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef CLIENT_COULDNOTESTABLISHCONNECTIONEXCEPTION_H
#define CLIENT_COULDNOTESTABLISHCONNECTIONEXCEPTION_H

#include <exception>

using namespace std;

class CouldNotEstablishConnectionException : exception {
public:
    virtual const char *what() const throw() {
        return "Could not establish connection";
    }
};

#endif //CLIENT_COULDNOTESTABLISHCONNECTIONEXCEPTION_H
