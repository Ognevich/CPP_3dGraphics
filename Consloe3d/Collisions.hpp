#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP
#include <iostream>
#include <Windows.h>
#include "config.hpp"

class Collisions {
public:
    template <typename T>
    bool checkObjectCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH]);

    template <typename T>
    bool checkObjectYWallTopCollision(T* object);

    template <typename T>
    bool checkObjectYWallBottomCollision(T* object);

    template <typename T>
    bool checkObjectXWallLeftCollision(T* object);

    template <typename T>
    bool checkObjectXWallRightCollision(T* object);

    template <typename T>
    bool checkObjectSpawnCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH]);

};

template<typename T>
inline bool Collisions::checkObjectCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH])
{
    auto futureCoords = object->getFutureCoord();
    for (const auto& coord : futureCoords) {
        if (map[coord.Y][coord.X] != ' ') return true;
    }
    return false;
}

template<typename T>
inline bool Collisions::checkObjectYWallTopCollision(T* object)
{
    float scaledRadiusY = object->getRadius() / object->getYOffset();
    return (object->getPos().Y + scaledRadiusY >= MAP_HEIGHT / 2);
}

template<typename T>
inline bool Collisions::checkObjectYWallBottomCollision(T* object)
{
    float scaledRadiusY = object->getRadius() / object->getYOffset();
    return (object->getPos().Y - scaledRadiusY <= -(MAP_HEIGHT / 2));
}

template<typename T>
inline bool Collisions::checkObjectXWallRightCollision(T* object)
{
    return (object->getPos().X + object->getRadius() >= MAP_WIDTH / 2);
}

template<typename T>
inline bool Collisions::checkObjectSpawnCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH])
{
    auto objectCoord = object->getObjectCoords();

    for (const auto& coord : objectCoord) 
        if (map[coord.Y][coord.X] != ' ') return true;
    return false;
}

template<typename T>
inline bool Collisions::checkObjectXWallLeftCollision(T* object)
{
    return (object->getPos().X - object->getRadius() <= -(MAP_WIDTH / 2));
}

#endif