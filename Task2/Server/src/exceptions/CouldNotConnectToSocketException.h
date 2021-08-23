//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_COULDNOTCONNECTTOSOCKETEXCEPTION_H
#define SERVER_COULDNOTCONNECTTOSOCKETEXCEPTION_H

#include <exception>

using namespace std;

class CouldNotConnectToSocketException : exception {
public:
    virtual const char *what() const throw() {
        return "Could not connect to socket";
    }
};

#endif //SERVER_COULDNOTCONNECTTOSOCKETEXCEPTION_H
