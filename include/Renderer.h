#pragma once

#include "Map.h"
#include "Player.h"
#include "Raycaster.h"

#include <iosfwd>

class Renderer
{
public:
    Renderer(int width, int height);

    void render(const Map& map, const Player& player, std::ostream& output) const;

private:
    int width_;
    int height_;
    Raycaster raycaster_;
};
