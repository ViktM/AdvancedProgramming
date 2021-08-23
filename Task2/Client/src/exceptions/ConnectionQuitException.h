//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef CLIENT_CONNECTIONQUITEXCEPTION_H
#define CLIENT_CONNECTIONQUITEXCEPTION_H

#include <exception>

using namespace std;

class ConnectionQuitException : exception {
public:
    virtual const char *what() const throw() {
        return "Connection to server terminated";
    }
};

#endif //CLIENT_CONNECTIONQUITEXCEPTION_H
