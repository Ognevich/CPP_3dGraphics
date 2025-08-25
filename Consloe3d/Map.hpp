#ifndef MAP_H
#define MAP_H
#include "config.hpp"
#include "Circle.hpp"

class Map {
private:
	char map[MAP_HEIGHT][MAP_WIDTH];
public:
	Map();

	void showMap();
	void initMap();

	template <typename T>
	void updateMap(T * object);

    template <typename T>
    void addObjectToMapArray(T * object);

};


template <typename T>
inline void Map::updateMap(T* object)
{

    object->updateObjectPos();
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

#endif