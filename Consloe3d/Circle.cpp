#include "Circle.hpp"
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

void Circle::setPos(Vector2 pos) {
    this->pos = pos;
}

Vector2 Circle::getPos() const {
    return this->pos;
}

void Circle::invertDirectionX() {
    this->Direction.X = -this->Direction.X;
}

void Circle::invertDirectionY() {
    this->Direction.Y = -this->Direction.Y;
}

char Circle::createGradient(int radius, float dist)
{
    float norm = dist / radius;
    int idx = static_cast<int>(norm * (gradient.size() - 1));

    idx = std::clamp(idx, 0, static_cast<int>(gradient.size() - 1));
    return gradient[idx];
}

Vector2 Circle::getDirection() const {
    return this->Direction;
}

int Circle::getRadius() const {
    return this->radius;
}

float Circle::calculateSquareDistance(int posX, int posY) const
{
    int centerX = MAP_WIDTH / 2 + pos.X;
    int centerY = MAP_HEIGHT / 2 + pos.Y;

    float dx = posX - centerX;
    float dy = (posY - centerY) * yOffset;

    return std::sqrt(dx * dx + dy * dy);
}
