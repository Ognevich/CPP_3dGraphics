#ifndef MAP_H
#define MAP_H
#include "config.hpp"

class Map {
private:
	char map[MAP_HEIGHT][MAP_WIDTH];

public:
	void showMap();
	void initMap();
};

#endif