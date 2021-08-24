//
// Created by Mezei, Szilvia (Associate Software Developer) on 24/08/2021.
//

#ifndef GAME_DRAWABLEGAMECOMPONENT_H
#define GAME_DRAWABLEGAMECOMPONENT_H

#include <string>
#include <iostream>
#include "GameComponent.h"

using namespace std;

class DrawableGameComponent : public GameComponent {
public:
    enum Direction : unsigned char {
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4
    };

    Direction direction;
    const int SCREEN_HEIGHT = 20;
    const int SCREEN_WIDTH = 80;

private:
    int x;
    int y;
    string currentDirection;

public:
    DrawableGameComponent(int x, int y) : GameComponent() {
        this->x = x;
        this->y = y;
        direction = Direction::Up;
    }

    void Update(const tm *eventTime) override {
        GameComponent::Update(eventTime);
        CurrentPosition();
        Draw();
        ChangeDirection();
    }

private:
    void ChangeDirection() {
        int randomDirection = (rand() % 4) + 1;
        while (randomDirection == direction)
            randomDirection = (rand() % 4) + 1;
        direction = static_cast<Direction>(randomDirection);
    };

    void Draw() {
        cout << currentDirection + " : " + "X : " + to_string(x) + ", Y : " + to_string(y) << endl;
    };

    void CurrentPosition() {
        switch (direction) {
            case Up:
                y++;
                if (y > SCREEN_HEIGHT) {
                    y = SCREEN_HEIGHT;
                }
                currentDirection = "Up";
                break;
            case Down:
                y--;
                if (y < 0) {
                    y = 0;
                }
                currentDirection = "Down";
                break;
            case Right:
                x++;
                if (x > SCREEN_WIDTH) {
                    x = SCREEN_WIDTH;
                }
                currentDirection = "Right";
                break;
            case Left:
                x--;
                if (x < 0) {
                    x = 0;
                }
                currentDirection = "Left";
                break;
            default:
                cout << "No motion has been detected" << endl;
                break;
        }
    };
};

#endif //GAME_DRAWABLEGAMECOMPONENT_H
