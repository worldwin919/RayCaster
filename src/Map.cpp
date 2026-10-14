#include "Map.h"

#include <fstream>
#include <stdexcept>
#include <utility>

Map::Map(std::vector<std::string> cells)
    : cells_(std::move(cells))
{
}

Map Map::loadFromFile(const std::string& path)
{
    std::ifstream input(path);
    if (!input)
    {
        throw std::runtime_error("could not open map file: " + path);
    }

    std::vector<std::string> cells;
    std::string row;
    while (std::getline(input, row))
    {
        if (!row.empty() && row.back() == '\r')
        {
            row.pop_back();
        }

        if (!row.empty())
        {
            cells.push_back(row);
        }
    }

    if (cells.empty() || cells.front().empty())
    {
        throw std::runtime_error("map file is empty: " + path);
    }

    const std::size_t expectedWidth = cells.front().size();
    for (const std::string& mapRow : cells)
    {
        if (mapRow.size() != expectedWidth)
        {
            throw std::runtime_error("map rows must all have the same width: " + path);
        }

        for (char tile : mapRow)
        {
            if (tile != '0' && tile != '1')
            {
                throw std::runtime_error("map tiles must be 0 (empty) or 1 (wall): " + path);
            }
        }
    }

    for (std::size_t x = 0; x < expectedWidth; ++x)
    {
        if (cells.front()[x] != '1' || cells.back()[x] != '1')
        {
            throw std::runtime_error("map must have a wall border: " + path);
        }
    }

    for (const std::string& mapRow : cells)
    {
        if (mapRow.front() != '1' || mapRow.back() != '1')
        {
            throw std::runtime_error("map must have a wall border: " + path);
        }
    }

    return Map(std::move(cells));
}

bool Map::isWall(int x, int y) const
{
    if (x < 0 || y < 0 || x >= width() || y >= height())
    {
        return true;
    }

    return cells_[static_cast<std::size_t>(y)][static_cast<std::size_t>(x)] == '1';
}

int Map::width() const
{
    return static_cast<int>(cells_.front().size());
}

int Map::height() const
{
    return static_cast<int>(cells_.size());
}
