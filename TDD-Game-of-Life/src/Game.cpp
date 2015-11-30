//
// Created by dima on 22.11.15.
//

#include "Game.hpp"


Game::Game() {

}


void Game::run(int argc, char** argv) {

    if (argc != 3) {
        throw std::invalid_argument("Invalid grid size!");
    }
    int m(atoi(argv[1])), n(atoi(argv[2]));

    Parser parser(std::cin);
    auto grid = parser.getGrid(m, n);

    Controller controller(m, n);
    View view(std::cout, m, n);


    auto next_grid = controller.nextGenerations(grid);
    view.print(next_grid);
}

