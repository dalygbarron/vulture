#include "../core/Game.hh"
#include "../core/UserAction.hh"
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "bongo" << std::endl;
    Game game();
    game.update(DOWN);
    game.update(ESCAPE);
    return 0;
}
