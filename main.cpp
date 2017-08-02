#include "src/Game.h"

int main() {
    Game *game = new Game();
    game->initialize();
    game->run();

    delete game;
    return 0;
}