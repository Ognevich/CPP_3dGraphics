#include "ProjectControl.h"

void ProjectControl::init()
{
    map.initMap();   
}

void ProjectControl::run()
{
    Utills utills;
    Circle circle(4, 1.72);

    while (true) {
        utills.clearGameScreen();

        map.showMap();
    }

}

void ProjectControl::shutdown()
{
}
