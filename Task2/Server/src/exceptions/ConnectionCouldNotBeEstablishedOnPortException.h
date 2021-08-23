//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_CONNECTIONCOULDNOTBEESTABLISHEDONPORTEXCEPTION_H
#define SERVER_CONNECTIONCOULDNOTBEESTABLISHEDONPORTEXCEPTION_H

#include <exception>

using namespace std;

class ConnectionCouldNotBeEstablishedOnPortException : exception {
public:
    virtual const char *what() const throw() {
        return "Connection could not be established on port";
    }
};

#endif //SERVER_CONNECTIONCOULDNOTBEESTABLISHEDONPORTEXCEPTION_H
