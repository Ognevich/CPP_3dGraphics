#include "Circle.hpp"

Circle::Circle(int radius, float offset)
    : GameObjects("@%#*+=-:.", offset), radius(radius)
{
    isDirection.X = (rand() % 2 == 0) ? -1 : 1;
    isDirection.Y = (rand() % 2 == 0) ? -1 : 1;

    pos.X = (rand() % (MAP_WIDTH - 2 * radius)) - (MAP_WIDTH / 2 - radius);
    pos.Y = (rand() % (MAP_HEIGHT - 2 * (int)(radius / yOffset))) - (MAP_HEIGHT / 2 - (int)(radius / yOffset));

    saveObjectCoordToVector();
}

void Circle::saveObjectCoordToVector()
{
    objectCoords.clear();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {

            float dist = calculateSquareDistance(j,i);

            if (dist < radius) {
                objectCoords.push_back({ j, i });
            }
        }
    }
}

void Circle::setPos(Vector2 pos)
{
    this->pos = pos;
}

void Circle::setIsDirectionX(int isDirection)
{
    this->isDirection.X = isDirection;
}

void Circle::setIsDirectionY(int isDirection)
{
    this->isDirection.Y = isDirection;
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

float Circle::calculateSquareDistance(int posX, int posY)
{
    int centerX = MAP_WIDTH / 2 + getPos().X;
    int centerY = MAP_HEIGHT / 2 + getPos().Y;

    float dx = posX - centerX;
    float dy = (posY - centerY) * yOffset;
    float dist = sqrt(dx * dx + dy * dy);

    return dist;
}

float Circle::getyOffset()
{
    return yOffset;
}

Vector2 Circle::getPos()
{
    return this->pos;
}

Vector2 Circle::getIsDirection()
{
    return this->isDirection;
}

int Circle::getRadius()
{
    return this->radius;
}
