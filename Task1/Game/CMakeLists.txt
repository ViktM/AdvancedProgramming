cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game src/main.cpp src/Game.cpp src/Game.h src/GameComponent.cpp src/GameComponent.h src/DrawableGameComponent.cpp src/DrawableGameComponent.h)