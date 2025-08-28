#include "Objects.hpp"

GameObjects::GameObjects(const std::string& grad, float offset)
	: gradient(grad), yOffset(offset), pos{ 0,0 }, Direction{ 1,1 } {
}

int GameObjects::getObjectCoordVectorLength() const
{
    return static_cast<int>(objectCoords.size());
}

const std::vector<Vector2>& GameObjects::getObjectCoords()
{
    return objectCoords;
}

float GameObjects::getYOffset() const
{
    return yOffset;
}

void GameObjects::invertDirectionX()
{
    Direction.X = -Direction.X;
}

void GameObjects::invertDirectionY()
{
    Direction.Y = -Direction.Y;
}

Vector2 GameObjects::getDirection() const
{
    return Direction;
}

Vector2 GameObjects::getPos() const
{
    return pos;
}

std::vector<Vector2> GameObjects::getFutureCoord() const
{
    std::vector<Vector2> future;
    for (auto& coord : objectCoords) {
        future.push_back({ coord.X + Direction.X, coord.Y + Direction.Y });
    }
    return future;
}

std::vector<Vector2> GameObjects::getFutureCoordVectorX() const
{
    std::vector<Vector2> future;

    for (const auto& coord : objectCoords) {
        future.push_back({ coord.X + Direction.X, coord.Y });
    }
    return future;
}


std::vector<Vector2> GameObjects::getFutureCoordVectorY() const
{
    std::vector<Vector2> future;

    for (const auto& coord : objectCoords) {
        future.push_back({ coord.X , coord.Y + Direction.Y });
    }
    return future;

}

void GameObjects::setPos(Vector2 p)
{
    pos = p;
}