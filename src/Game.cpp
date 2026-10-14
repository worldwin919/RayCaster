#include "Game.h"

#include "Map.h"
#include "Player.h"
#include "Renderer.h"

#include <iostream>

void Game::run() const
{
    const Map map = Map::loadFromFile("maps/demo.map");
    const Player player{3.5, 3.5, 0.0};
    const Renderer renderer(80, 24);

    std::cout << "RayCaster - sample view\n\n";
    renderer.render(map, player, std::cout);
    std::cout << "\nASCII preview | WASD movement and graphics are not implemented yet.\n";
}
