#pragma once

#include <string>
#include <vector>

class Map
{
public:
    static Map loadFromFile(const std::string& path);

    bool isWall(int x, int y) const;
    int width() const;
    int height() const;

private:
    explicit Map(std::vector<std::string> cells);

    std::vector<std::string> cells_;
};
