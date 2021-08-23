#include <iostream>
#include "Server.h"

using namespace std;

int main() {
    std::cout << "Hello, Server!" << std::endl;

    auto *server = new Server();

    server->Initialise();

    return 0;
}
