#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP
#include <iostream>
#include "config.hpp"

class Collisions {
public:
    template <typename T>
    bool checkObjectWallCollision(T* object);

    template <typename T>
    bool checkObjectYWallTopCollision(T* object);

    template <typename T>
    bool checkObjectYWallBottomCollision(T* object);

    template <typename T>
    bool checkObjectXWallLeftCollision(T* object);

    template <typename T>
    bool checkObjectXWallRightCollision(T* object);
};

template<typename T>
inline bool Collisions::checkObjectWallCollision(T* object)
{
    return checkObjectYWallTopCollision(object) ||
        checkObjectYWallBottomCollision(object) ||
        checkObjectXWallLeftCollision(object) ||
        checkObjectXWallRightCollision(object);
}

template<typename T>
inline bool Collisions::checkObjectYWallTopCollision(T* object)
{
    float scaledRadiusY = object->getRadius() / object->getyOffset();
    return (object->getPos().Y + scaledRadiusY >= MAP_HEIGHT / 2);
}

template<typename T>
inline bool Collisions::checkObjectYWallBottomCollision(T* object)
{
    float scaledRadiusY = object->getRadius() / object->getyOffset();
    return (object->getPos().Y - scaledRadiusY <= -(MAP_HEIGHT / 2));
}

template<typename T>
inline bool Collisions::checkObjectXWallRightCollision(T* object)
{
    return (object->getPos().X + object->getRadius() >= MAP_WIDTH / 2);
}

template<typename T>
inline bool Collisions::checkObjectXWallLeftCollision(T* object)
{
    return (object->getPos().X - object->getRadius() <= -(MAP_WIDTH / 2));
}

#endif