#include "Map.hpp"

Map::Map()
{
	initMap();
}

void Map::showMap()
{
    std::string frame;

    for (int yPos = 0; yPos < MAP_HEIGHT; yPos++) {
        for (int xPos = 0; xPos < MAP_WIDTH; xPos++) {
            frame += map[yPos][xPos];
        }
        frame += "\n";
    }

    std::cout << frame;
}
void Map::initMap()
{
	for (int yPos = 0; yPos < MAP_HEIGHT; yPos++) {
		for (int xPos = 0; xPos < MAP_WIDTH; xPos++) {
			map[yPos][xPos] = ' ';
		}
	}
}