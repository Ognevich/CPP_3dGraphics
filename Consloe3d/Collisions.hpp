#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP
#include <iostream>
#include <Windows.h>
#include "config.hpp"
#include "Circle.hpp"

class Collisions {
public:

    template <typename T>
    bool checkObjectXCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH]);

    template <typename T>
    bool checkObjectYCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH]);

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

    // 🔹 нове: перевірка колізій між двома Circle
    bool checkCirclesCollision(const Circle& a, const Circle& b);
};


template<typename T>
inline bool Collisions::checkObjectXCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH])
{
    auto futureCoords = object->getFutureCoordVectorX();
    for (const auto& coord : futureCoords) {
        if (map[coord.Y][coord.X] != ' ') return true;
    }
    return false;
}

template<typename T>
inline bool Collisions::checkObjectYCollision(T* object, char(&map)[MAP_HEIGHT][MAP_WIDTH])
{
    auto futureCoords = object->getFutureCoordVectorY();
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

inline bool Collisions::checkCirclesCollision(const Circle& a, const Circle& b) {
    float dx = a.getPos().X - b.getPos().X;
    float dy = a.getPos().Y - b.getPos().Y;
    float distanceSq = dx * dx + dy * dy;
    float radiusSum = a.getRadius() + b.getRadius();
    return distanceSq <= (radiusSum * radiusSum);
}

#endif