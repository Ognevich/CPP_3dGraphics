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

void Map::addSquareToMapArray()
{
    int xPos = (MAP_HEIGHT / 2);
    int yPos = (MAP_WIDTH / 2);

    for (int i = xPos-5; i < (MAP_HEIGHT / 2)+5;i++) {
        for (int j = yPos-5; j < (MAP_WIDTH / 2) + 5; j++) {
            map[i][j] = '#';
        }
    }

}
