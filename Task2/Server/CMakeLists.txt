cmake_minimum_required(VERSION 3.19)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server src/main.cpp src/Server.cpp src/Server.h src/exceptions/NoSocketAvailableException.cpp src/exceptions/NoSocketAvailableException.h src/exceptions/CouldNotBindPortException.cpp src/exceptions/CouldNotBindPortException.h src/exceptions/CouldNotConnectToSocketException.cpp src/exceptions/CouldNotConnectToSocketException.h src/exceptions/CouldNotConnectToClientException.cpp src/exceptions/CouldNotConnectToClientException.h src/Comms.cpp src/Comms.h src/exceptions/ConnectionCouldNotBeEstablishedOnPortException.cpp src/exceptions/ConnectionCouldNotBeEstablishedOnPortException.h src/exceptions/NoResponseReceivedException.cpp src/exceptions/NoResponseReceivedException.h)