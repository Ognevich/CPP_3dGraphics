#include "Square.hpp"
#include "config.hpp"
#include <algorithm>
#include <cmath>

Square::Square(int radius, float offset, const std::string& grad)
    : GameObjects(grad, offset), radius(radius)
{
    saveObjectCoordToVector();
}

void Square::saveObjectCoordToVector()
{
    objectCoords.clear();
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            float dist = calculateSquareDistance(j, i);
            if (dist < radius) {
                objectCoords.push_back({ j, i });
            }
        }
    }
}

char Square::createGradient(float dist)
{
    float norm = dist / radius;
    int idx = static_cast<int>(norm * (gradient.size() - 1));
    idx = std::max(0, std::min(idx, (int)gradient.size() - 1));
    return gradient[idx];
}

float Square::calculateSquareDistance(int posX, int posY) const
{
    int centerX = MAP_WIDTH / 2 + pos.X;
    int centerY = MAP_HEIGHT / 2 + pos.Y;

    int dx = std::abs(posX - centerX);
    int dy = std::abs(posY - centerY);
    return std::max(dx, dy);
}

