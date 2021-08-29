#include <iostream>
#include "DrawableGameComponent.h"
#include "Game.h"

using namespace std;

int GameComponent::instances = 0;

void Init() {
    cout << "Init game" << endl;
}

void Term() {
    cout << "Term game" << endl;
}

int main() {
    std::cout << "Hello, Game!" << std::endl;

    Game game = Game(2);

    game.SetInitialise(Init);

    game.SetTerminate(Term);

    game.Add(new GameComponent());

    game.Add(new DrawableGameComponent(0, 0));

    game.Run();

    return 0;
}
