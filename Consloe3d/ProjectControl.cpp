#include "ProjectControl.hpp"

ProjectControler::ProjectControler()
{
}

void ProjectControler::init()
{
    map.initMap();
    map.addSquareToMapArray(60, 15);
}

void ProjectControler::run()
{
    Utills utills;

    int objectAmount = 5;
    addRandomCirclesToVector(objectAmount);
    while (true) {
        Sleep(15);
        utills.clearGameScreen();
        map.initMap();
        map.addSquareToMapArray(60,15);
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
        if (collisions.checkObjectSpawnCollision(&circle, map.getMap())) {
            i--;
        }
        else {
            circleVector.push_back(circle);
        }
    }

}
