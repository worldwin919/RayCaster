#include "Raycaster.h"

#include <cmath>
#include <limits>

RayHit Raycaster::cast(const Map& map, const Player& player, double cameraX) const
{
    constexpr double cameraPlaneScale = 0.66;
    const double directionX = std::cos(player.angle);
    const double directionY = std::sin(player.angle);
    const double rayDirectionX = directionX - directionY * cameraPlaneScale * cameraX;
    const double rayDirectionY = directionY + directionX * cameraPlaneScale * cameraX;

    int mapX = static_cast<int>(player.x);
    int mapY = static_cast<int>(player.y);

    const double deltaDistanceX = rayDirectionX == 0.0
        ? std::numeric_limits<double>::infinity()
        : std::abs(1.0 / rayDirectionX);
    const double deltaDistanceY = rayDirectionY == 0.0
        ? std::numeric_limits<double>::infinity()
        : std::abs(1.0 / rayDirectionY);

    int stepX;
    int stepY;
    double sideDistanceX;
    double sideDistanceY;

    if (rayDirectionX < 0.0)
    {
        stepX = -1;
        sideDistanceX = (player.x - mapX) * deltaDistanceX;
    }
    else
    {
        stepX = 1;
        sideDistanceX = (mapX + 1.0 - player.x) * deltaDistanceX;
    }

    if (rayDirectionY < 0.0)
    {
        stepY = -1;
        sideDistanceY = (player.y - mapY) * deltaDistanceY;
    }
    else
    {
        stepY = 1;
        sideDistanceY = (mapY + 1.0 - player.y) * deltaDistanceY;
    }

    bool verticalSide = false;
    while (!map.isWall(mapX, mapY))
    {
        if (sideDistanceX < sideDistanceY)
        {
            sideDistanceX += deltaDistanceX;
            mapX += stepX;
            verticalSide = true;
        }
        else
        {
            sideDistanceY += deltaDistanceY;
            mapY += stepY;
            verticalSide = false;
        }
    }

    const double distance = verticalSide
        ? sideDistanceX - deltaDistanceX
        : sideDistanceY - deltaDistanceY;

    return {std::max(distance, 0.0001), verticalSide};
}
