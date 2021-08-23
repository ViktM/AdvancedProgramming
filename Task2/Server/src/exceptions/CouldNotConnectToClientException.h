//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_COULDNOTCONNECTTOCLIENTEXCEPTION_H
#define SERVER_COULDNOTCONNECTTOCLIENTEXCEPTION_H

#include <exception>

using namespace std;

class CouldNotConnectToClientException : exception {
public:
    virtual const char *what() const throw() {
        return "Could not establish connection with client";
    }
};

#endif //SERVER_COULDNOTCONNECTTOCLIENTEXCEPTION_H
