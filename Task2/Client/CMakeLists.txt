cmake_minimum_required(VERSION 3.19)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client src/main.cpp src/Client.cpp src/Client.h src/exceptions/NoSocketAvailableException.cpp src/exceptions/NoSocketAvailableException.h src/Comms.cpp src/Comms.h src/exceptions/CouldNotEstablishConnectionException.cpp src/exceptions/CouldNotEstablishConnectionException.h src/exceptions/CouldNotSendUserInputException.cpp src/exceptions/CouldNotSendUserInputException.h src/exceptions/ConnectionQuitException.cpp src/exceptions/ConnectionQuitException.h src/exceptions/NoResponseFromServerException.cpp src/exceptions/NoResponseFromServerException.h)