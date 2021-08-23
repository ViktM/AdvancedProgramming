//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "exceptions/NoSocketAvailableException.h"
#include "Comms.h"
#include "exceptions/CouldNotEstablishConnectionException.h"
#include "exceptions/CouldNotSendUserInputException.h"
#include "exceptions/ConnectionQuitException.h"
#include "exceptions/NoResponseFromServerException.h"

class Client : public Comms {
public:
    Client() = default;

    int Initialise() override {
        int newSocket;
        sockaddr_in localSocket;
        configureConnection(newSocket, localSocket);

        establishConnection(newSocket, localSocket);

        return handleRequestToServer(newSocket);
    }

private:
    static void configureConnection(int &newSocket, sockaddr_in &localSocket) {
        newSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (newSocket == -1) {
            throw NoSocketAvailableException();
        }

        int portNumber = 5400;
        string homeIp = "127.0.0.1";
        localSocket.sin_family = AF_INET;
        localSocket.sin_port = htons(portNumber);
        inet_pton(AF_INET, homeIp.c_str(), &localSocket.sin_addr);
    }

    static void establishConnection(int newSocket, sockaddr_in &localSocket) {
        int connection = connect(newSocket, (sockaddr *) &localSocket, sizeof(localSocket));

        if (connection == -1) {
            throw CouldNotEstablishConnectionException();
        }
    }

    static int handleRequestToServer(int newSocket) {
        char buffer[4096];
        string input;

        while (true) {
            cout << "User input: " << endl;
            getline(cin, input);

            int sendInput = send(newSocket, input.c_str(), input.size() + 1, 0);

            if (sendInput == -1) {
                throw CouldNotSendUserInputException();
                continue; // break here or continue to try again - I decided to break
            }

            memset(buffer, 0, 4096);

            if (strcmp(input.c_str(), "QUIT") == 0) {
                throw ConnectionQuitException();
            }

            int response = recv(newSocket, buffer, 4096, 0);

            if (response == -1) {
                throw NoResponseFromServerException();
            } else {
                cout << "Server confirms response: " << string(buffer, response) << endl;
            }
        }
    }
};

#endif //CLIENT_CLIENT_H
