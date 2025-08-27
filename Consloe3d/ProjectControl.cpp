#include "ProjectControl.hpp"

ProjectControler::ProjectControler()
{
}

void ProjectControler::init()
{
}

void ProjectControler::run()
{
    Utills utills;

    int objectAmount = 2;
    addRandomCirclesToVector(objectAmount);
    while (true) {
        Sleep(15);
        utills.clearGameScreen();
        map.initMap();
        map.addSquareToMapArray(MAP_HEIGHT/2,MAP_WIDTH/2);
        map.addSquareToMapArray(5,5);
        for (int i = 0; i < objectAmount; i++) {
            map.updateMap(&circleVector[i]);
        }

        map.showMap();
    }

}

void ProjectControler::shutdown()
{
}

void ProjectControler::addRandomCirclesToVector(int circleAmount)
{
    for (int i = 0; i < circleAmount; i++) {
        Circle circle(rand() % 4 + 4, 1.72);
        circleVector.push_back(circle);
    }

}
