//
// Created by Mezei, Szilvia (Associate Software Developer) on 23/08/2021.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include "exceptions/NoSocketAvailableException.h"
#include "exceptions/CouldNotBindPortException.h"
#include "exceptions/CouldNotConnectToSocketException.h"
#include "exceptions/CouldNotConnectToClientException.h"
#include "Comms.h"
#include "exceptions/ConnectionCouldNotBeEstablishedOnPortException.h"
#include "exceptions/NoResponseReceivedException.h"

class Server : public Comms { ;
public:
    Server() = default;

    int Initialise() override {
        int newSocket;
        sockaddr_in localSocket{};

        configureConnection(newSocket, localSocket);

        newSocket = bindSocket(newSocket, localSocket);

        listenOnSocket(newSocket);

        int clientSocket = initialiseClient(newSocket);

        close(newSocket);

        handleClientResponse(clientSocket);

        close(clientSocket);
        return 0;
    }

private:
    static void configureConnection(int &newSocket, sockaddr_in &localSocket) {
        newSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (newSocket == -1) {
            throw NoSocketAvailableException();
        }

        int portNumber = 5400;
        string homeIp = "0.0.0.0";
        localSocket.sin_family = AF_INET;
        localSocket.sin_port = htons(portNumber);
        inet_pton(AF_INET, homeIp.c_str(), &localSocket.sin_addr);
    };

    static int bindSocket(int newSocket, sockaddr_in &localSocket) {
        if (::bind(newSocket, (sockaddr *) &localSocket, sizeof(localSocket)) == -1) {
            throw CouldNotBindPortException();
        }
        return newSocket;
    }

    static void listenOnSocket(int newSocket) {
        if (listen(newSocket, SOMAXCONN) == -1) {
            throw CouldNotConnectToSocketException();
        }
    }

    static int initialiseClient(int newSocket) {
        sockaddr_in client{};
        socklen_t clientSize = sizeof(client);
        char host[NI_MAXHOST];
        char servicePort[NI_MAXSERV];

        int clientSocket = accept(newSocket, (sockaddr *) &client, &clientSize);

        if (clientSocket == -1) {
            throw CouldNotConnectToClientException();
        }

        if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, servicePort, NI_MAXSERV, 0) == 0) {
            cout << "Connection established on port " << servicePort << endl;
        } else {
            throw ConnectionCouldNotBeEstablishedOnPortException();
        }
        return clientSocket;
    }

    static void handleClientResponse(int clientSocket) {
        char buffer[4096];

        while (true) {
            memset(buffer, 0, 4096);

            long response = recv(clientSocket, buffer, 4096, 0);
            if (response == -1) {
                throw NoResponseReceivedException();
            }
            if (response == 0) {
                throw new CouldNotConnectToClientException();
            }
            cout << "Client response: " << string(buffer, 0, response) << endl;
            send(clientSocket, buffer, response - 1, 0);
        }
    }
};

#endif //SERVER_SERVER_H
