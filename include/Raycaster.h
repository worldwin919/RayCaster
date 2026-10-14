#pragma once

#include "Map.h"
#include "Player.h"

struct RayHit
{
    double distance;
    bool verticalSide;
};

class Raycaster
{
public:
    RayHit cast(const Map& map, const Player& player, double cameraX) const;
};
