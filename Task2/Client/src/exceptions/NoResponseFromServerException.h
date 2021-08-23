//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef CLIENT_NORESPONSEFROMSERVEREXCEPTION_H
#define CLIENT_NORESPONSEFROMSERVEREXCEPTION_H

#include <exception>

using namespace std;

class NoResponseFromServerException : exception {
public:
    virtual const char *what() const throw() {
        return "There was no response from the server";
    }
};

#endif //CLIENT_NORESPONSEFROMSERVEREXCEPTION_H
