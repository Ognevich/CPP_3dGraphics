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

    int objectAmount = 32;
    addRandomCirclesToVector(objectAmount);


    while (true) {
        Sleep(15);
        utills.clearGameScreen();
        map.initMap();
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
        Circle circle(rand() % 5 + 5, 1.72);
        circleVector.push_back(circle);
    }

}
