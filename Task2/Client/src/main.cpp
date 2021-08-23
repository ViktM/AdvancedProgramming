#include <iostream>
#include "Client.h"

int main() {
    std::cout << "Hello, Client!" << std::endl;

    auto *client = new Client();

    client->Initialise();

    return 0;
}
