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

	template <typename T>
	void updateMap(T * object);

    template <typename T>
    void addObjectToMapArray(T * object);

    template <typename T>
    void updateObjectPos(T * object);

    template <typename T>
    void updateObjectDirection(T* object);

};


template <typename T>
inline void Map::updateMap(T* object)
{
    updateObjectDirection(object);
    updateObjectPos(object);
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
            int radius = object->getRadius();

            map[coord.Y][coord.X] = object->createGradient(radius, dist);
        }
    }
}

template<typename T>
inline void Map::updateObjectPos(T* object)
{
    Vector2 newPos;

    newPos.X = object->getPos().X;
    newPos.Y = object->getPos().Y;

    newPos.X += object->getIsDirection().X;
    newPos.Y += object->getIsDirection().Y;
    
    object->setPos(newPos);
    
}

template<typename T>
inline void Map::updateObjectDirection(T* object)
{
    if (collisions.checkObjectXWallRightCollision(object))  { object->setIsDirectionX(-1); }
    if (collisions.checkObjectXWallLeftCollision(object))   { object->setIsDirectionX(+1); }

    if (collisions.checkObjectYWallTopCollision(object))    { object->setIsDirectionY(-1); }
    if (collisions.checkObjectYWallBottomCollision(object)) { object->setIsDirectionY(+1); }

}

#endif