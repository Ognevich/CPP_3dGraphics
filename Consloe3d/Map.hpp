#ifndef MAP_H
#define MAP_H

#include "config.hpp"
#include "Circle.hpp"
#include "Collisions.hpp"

class Map {
private:
    char map[MAP_HEIGHT][MAP_WIDTH];
    Collisions collisions;

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

    void addSquareToMapArray(int xPos, int yPos);
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
inline void Map::updateObjectDirection(T* object)
{

    if (collisions.checkObjectXWallRightCollision(object))  { object->invertDirectionX(); }
    if (collisions.checkObjectXWallLeftCollision(object))   { object->invertDirectionX(); }

    if (collisions.checkObjectYWallTopCollision(object))    { object->invertDirectionY(); }
    if (collisions.checkObjectYWallBottomCollision(object)) { object->invertDirectionY(); }

    if (collisions.checkObjectXCollision(object, map))      { object->invertDirectionX(); }

    if (collisions.checkObjectYCollision(object, map))      { object->invertDirectionY(); }

}

#endif 