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

char(&Map::getMap())[MAP_HEIGHT][MAP_WIDTH]{
    return map;
}

void Map::addSquareToMapArray(int xPos, int yPos)
{
    for (int i = yPos-5; i < yPos+5;i++) {
        for (int j = xPos-5; j < xPos + 5; j++) {
            map[i][j] = '#';
        }
    }

}
