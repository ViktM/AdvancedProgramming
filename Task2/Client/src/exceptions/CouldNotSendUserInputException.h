//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef CLIENT_COULDNOTSENDUSERINPUTEXCEPTION_H
#define CLIENT_COULDNOTSENDUSERINPUTEXCEPTION_H

#include <exception>

using namespace std;

class CouldNotSendUserInputException : exception {
public:
    virtual const char *what() const throw() {
        return "Could not send user input to server";
    }
};

#endif //CLIENT_COULDNOTSENDUSERINPUTEXCEPTION_H
