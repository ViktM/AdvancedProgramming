//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_NORESPONSERECEIVEDEXCEPTION_H
#define SERVER_NORESPONSERECEIVEDEXCEPTION_H

#include <exception>

using namespace std;

class NoResponseReceivedException : exception {
public:
    virtual const char *what() const throw() {
        return "No response received from client";
    }
};

#endif //SERVER_NORESPONSERECEIVEDEXCEPTION_H
