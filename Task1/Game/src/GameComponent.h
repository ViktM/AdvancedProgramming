//
// Created by Mezei, Szilvia (Associate Software Developer) on 24/08/2021.
//

#ifndef GAME_GAMECOMPONENT_H
#define GAME_GAMECOMPONENT_H

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class GameComponent {
private:
    int id;
    static int instances;

public:
    GameComponent() {
        id = ++instances;
    }

    virtual void Update(const tm *time) {
        cout << "ID : " + to_string(id) + " Updated @ " << put_time(time, "%X") << endl;

    };
};

#endif //GAME_GAMECOMPONENT_H
