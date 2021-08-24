//
// Created by Mezei, Szilvia (Associate Software Developer) on 24/08/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "GameComponent.h"
#include <thread>

int static UPDATES = 5;

typedef void (*FP)();

class Game {
private:
    GameComponent *components[2]{};
    FP initialise{};
    FP terminate{};
    const int TICKS_1000MS = 1000;
    int componentCount = 0;
    int maxComponents;

public:
    explicit Game(int maxComponents) {
        this->maxComponents = maxComponents;
    };

    void Add(GameComponent *gameComponent) {
        components[componentCount++] = gameComponent;
    };

    void Run() {
        initialise();

        for (int i = 0; i < UPDATES; i++) {
            for (int j = 0; j < maxComponents; j++) {
                auto now = chrono::system_clock::now();
                auto toTime = chrono::system_clock::to_time_t(now);
                tm *time = localtime(&toTime);
                components[j]->Update(time);
            }
            chrono::milliseconds sleep(TICKS_1000MS);
            this_thread::sleep_for(sleep);
        }
        terminate();
    };

    void SetInitialise(FP init) {
        initialise = init;
    };

    void SetTerminate(FP term) {
        terminate = term;
    };
};

#endif //GAME_GAME_H
