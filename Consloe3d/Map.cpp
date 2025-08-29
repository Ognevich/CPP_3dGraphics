#include "Map.hpp"


Map::Map()
{
	initMap();
}

void Map::resolveCirclesOverlap(Circle& a, Circle& b, float dist)
{
    float overlap = (a.getRadius() + b.getRadius()) - dist;

    Vector2 delta = Vector2::deltaVector(a, b);
    float nx = delta.Xf / dist;
    float ny = delta.Yf / dist;

    Vector2 posA = a.getPos();
    Vector2 posB = b.getPos();

    posA.X -= nx * overlap * 0.5f;
    posA.Y -= ny * overlap * 0.5f;
    posB.X += nx * overlap * 0.5f;
    posB.Y += ny * overlap * 0.5f;

    a.setPos(posA);
    b.setPos(posB);
}

void Map::bounceCircles(Circle& a, Circle& b)
{
    a.invertDirectionX();
    a.invertDirectionY();
    b.invertDirectionX();
    b.invertDirectionY();
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
