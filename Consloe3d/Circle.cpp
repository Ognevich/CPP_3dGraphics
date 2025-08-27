#include "Circle.hpp"
#include "config.hpp"
#include <cmath>
#include <algorithm>
#include <random>

Circle::Circle(int radius, float offset, const std::string& grad)
    : GameObjects(grad, offset), radius(radius)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dirDist(0, 1);
    Direction.X = dirDist(gen) == 0 ? -1 : 1;
    Direction.Y = dirDist(gen) == 0 ? -1 : 1;

    std::uniform_int_distribution<int> xDist(-(MAP_WIDTH / 2 - radius),
        (MAP_WIDTH / 2 - radius));
    std::uniform_int_distribution<int> yDist(-(MAP_HEIGHT / 2 - (int)(radius / yOffset)),
        (MAP_HEIGHT / 2 - (int)(radius / yOffset)));

    pos.X = xDist(gen);
    pos.Y = yDist(gen);

    saveObjectCoordToVector();
}

void Circle::saveObjectCoordToVector()
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

char Circle::createGradient(float dist)
{
    float norm = dist / radius;
    int idx = static_cast<int>(norm * (gradient.size() - 1));
    idx = std::max(0, std::min(idx, (int)gradient.size() - 1)); 
    return gradient[idx];
}

float Circle::calculateSquareDistance(int posX, int posY) const
{
    int centerX = MAP_WIDTH / 2 + pos.X;
    int centerY = MAP_HEIGHT / 2 + pos.Y;

    float dx = posX - centerX;
    float dy = (posY - centerY) * yOffset;
    return std::sqrt(dx * dx + dy * dy);
}
