#include "Renderer.h"

#include <algorithm>
#include <ostream>
#include <stdexcept>

Renderer::Renderer(int width, int height)
    : width_(width),
      height_(height)
{
    if (width_ <= 0 || height_ <= 0)
    {
        throw std::invalid_argument("renderer dimensions must be positive");
    }
}

void Renderer::render(const Map& map, const Player& player, std::ostream& output) const
{
    constexpr char wallShades[] = {'#', 'X', 'x', '+', ':', '.'};
    constexpr char floorShades[] = {'.', '-', '_'};

    for (int y = 0; y < height_; ++y)
    {
        const double rowFromCenter = y - height_ / 2.0;
        for (int x = 0; x < width_; ++x)
        {
            const double cameraX = 2.0 * x / width_ - 1.0;
            const RayHit hit = raycaster_.cast(map, player, cameraX);
            const int wallHeight = std::min(
                height_,
                static_cast<int>(height_ / hit.distance));
            const int wallTop = (height_ - wallHeight) / 2;
            const int wallBottom = wallTop + wallHeight;

            if (y >= wallTop && y < wallBottom)
            {
                std::size_t shade = static_cast<std::size_t>(hit.distance / 2.0);
                shade = std::min(shade, sizeof(wallShades) - 1);
                if (!hit.verticalSide && shade + 1 < sizeof(wallShades))
                {
                    ++shade;
                }
                output << wallShades[shade];
            }
            else if (rowFromCenter > 0.0)
            {
                const double floorDistance = height_ / (2.0 * rowFromCenter);
                const std::size_t shade = std::min(
                    static_cast<std::size_t>(floorDistance / 3.0),
                    sizeof(floorShades) - 1);
                output << floorShades[shade];
            }
            else
            {
                output << ' ';
            }
        }
        output << '\n';
    }
}
