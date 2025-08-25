#include "Circle.hpp"

Circle::Circle(int radius, float offset)
    : GameObject("@%#*+=-:.", offset), radius(radius)
{
    isDirection.X = (rand() % 2 == 0) ? -1 : 1;
    isDirection.Y = (rand() % 2 == 0) ? -1 : 1;

    pos.X = (rand() % (MAP_WIDTH - 2 * radius)) - (MAP_WIDTH / 2 - radius);
    pos.Y = (rand() % (MAP_HEIGHT - 2 * (int)(radius / yOffset))) - (MAP_HEIGHT / 2 - (int)(radius / yOffset));

    saveObjectCoordToVector();
}

void Circle::updateObjectPos()
{
    if (pos.X + radius >= MAP_WIDTH / 2)  isDirection.X = -1;
    if (pos.X - radius <= -(MAP_WIDTH / 2)) isDirection.X = +1;

    float scaledRadiusY = radius / yOffset;

    if (pos.Y + scaledRadiusY >= MAP_HEIGHT / 2) isDirection.Y = -1;
    if (pos.Y - scaledRadiusY <= -(MAP_HEIGHT / 2)) isDirection.Y = +1;

    pos.X += isDirection.X;
    pos.Y += isDirection.Y;
}

void Circle::saveObjectCoordToVector()
{
    objectCoords.clear();

    int centerX = MAP_WIDTH / 2 + pos.X;
    int centerY = MAP_HEIGHT / 2 + pos.Y;

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            float dx = j - centerX;
            float dy = (i - centerY) * yOffset;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist < radius) {
                objectCoords.push_back({ j, i });
            }
        }
    }
}

char Circle::createGradient(int radius, float dist)
{
    float norm = dist / radius;
    int idx = (int)(norm * (gradient.size() - 1));
    return gradient[idx];
}

int Circle::getObjectCoordVectorLenght()
{
    return objectCoords.size();
}

bool Circle::isObjectCoordVectorValue(int xPos,int yPos)
{
    for (int k = 0; k < objectCoords.size(); k++) {
        if (objectCoords[k].X == xPos && objectCoords[k].Y == yPos) {
            return true;
        }
    }
    return false;
}

const std::vector<Vector2>& Circle::getObjectCoords() const
{
    return objectCoords;
}
