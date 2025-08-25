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
};


template <typename T>
void Map::updateMap(T* object)
{
    initMap(); // очистка карти

    object->updateObjectPos();
    object->saveObjectCoordToVector();

    for (auto& coord : object->getObjectCoords()) {
        if (coord.Y >= 0 && coord.Y < MAP_HEIGHT &&
            coord.X >= 0 && coord.X < MAP_WIDTH)
        {
            map[coord.Y][coord.X] = '#';
        }
    }
}

#endif