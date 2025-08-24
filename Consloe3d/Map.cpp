#include "Map.hpp"

void Map::showMap()
{
	for (int yPos = 0; yPos < MAP_HEIGHT; yPos++) {
		for (int xPos = 0; xPos < MAP_WIDTH; xPos++) {
			std::cout << map[yPos][xPos];
		}
		std::cout << "\n";
	}
}

void Map::initMap()
{
	for (int yPos = 0; yPos < MAP_HEIGHT; yPos++) {
		for (int xPos = 0; xPos < MAP_WIDTH; xPos++) {
			map[yPos][xPos] = ' ';
		}
	}
}
