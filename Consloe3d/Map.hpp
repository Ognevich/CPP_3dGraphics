#ifndef MAP_H
#define MAP_H

#include "config.hpp"
#include "Circle.hpp"
#include "Collisions.hpp"
#include <vector>

class Map {
private:
    char map[MAP_HEIGHT][MAP_WIDTH];
    Collisions collisions;
    Vector2 vector2;

    void resolveCirclesOverlap(Circle& a, Circle& b, float dist);
    void bounceCircles(Circle& a, Circle& b);
public:
    Map();

    void showMap();
    void initMap();
    char(&getMap())[MAP_HEIGHT][MAP_WIDTH];

    template <typename T>
    void updateMap(T* object);

    template <typename T>
    void addObjectToMapArray(T* object);

    template <typename T>
    void updateObjectPos(T* object);

    template <typename T>
    void updateObjectDirection(T* object);

    template <typename T>
    void handleWallXDirection(T* object);

    template <typename T>
    void handleWallYDirection(T* object);

    void addSquareToMapArray(int xPos, int yPos);

    void handleCirclesCollisions(std::vector<Circle>& circles);
};


template <typename T>
inline void Map::updateMap(T* object)
{
    for (auto& coord : object->getObjectCoords()) {
        if (coord.Y >= 0 && coord.Y < MAP_HEIGHT &&
            coord.X >= 0 && coord.X < MAP_WIDTH)
        {
            map[coord.Y][coord.X] = ' ';
        }
    }

    updateObjectPos(object);
    updateObjectDirection(object);
    object->saveObjectCoordToVector();
    addObjectToMapArray(object);
}

template<typename T>
inline void Map::addObjectToMapArray(T* object)
{
    for (auto& coord : object->getObjectCoords()) {
        if (coord.Y >= 0 && coord.Y < MAP_HEIGHT &&
            coord.X >= 0 && coord.X < MAP_WIDTH)
        {
            float dist = object->calculateSquareDistance(coord.X, coord.Y);
            map[coord.Y][coord.X] = object->createGradient(dist);
        }
    }
}

template<typename T>
inline void Map::updateObjectPos(T* object)
{
    Vector2 newPos = object->getPos();
    newPos.X += object->getDirection().X;
    newPos.Y += object->getDirection().Y;
    object->setPos(newPos);
}

template<typename T>
inline void Map::handleWallXDirection(T* object)
{
    if (collisions.checkObjectXWallRightCollision(object)) { object->invertDirectionX(); }
    if (collisions.checkObjectXWallLeftCollision(object)) { object->invertDirectionX(); }
}

template<typename T>
inline void Map::handleWallYDirection(T* object)
{
    if (collisions.checkObjectYWallTopCollision(object)) { object->invertDirectionY(); }
    if (collisions.checkObjectYWallBottomCollision(object)) { object->invertDirectionY(); }
}

template<typename T>
inline void Map::updateObjectDirection(T* object)
{
    handleWallXDirection(object);
    handleWallYDirection(object);

    if (collisions.checkObjectXCollision(object, map)) { object->invertDirectionX(); }
    if (collisions.checkObjectYCollision(object, map)) { object->invertDirectionY(); }
}

inline void Map::handleCirclesCollisions(std::vector<Circle>& circles) {
    for (size_t i = 0; i < circles.size(); i++) {
        for (size_t j = i + 1; j < circles.size(); j++) {
            if (collisions.checkCirclesCollision(circles[i], circles[j])) {
                float dist = Vector2::distanceBetweenCenters(circles[i], circles[j]);
                if (dist == 0) dist = 0.1f;

                resolveCirclesOverlap(circles[i], circles[j], dist);
                bounceCircles(circles[i], circles[j]);
            }
        }
    }
}

#endif
