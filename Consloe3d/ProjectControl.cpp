#include "ProjectControl.hpp"

ProjectControl::ProjectControl()
{
}

void ProjectControl::init()
{
}

void ProjectControl::run()
{
    Utills utills;
    Circle circle(4, 1.72);
    
    while (true) {
        Sleep(15);

        utills.clearGameScreen();
        map.updateMap(&circle); 
        map.showMap();
    }

}

void ProjectControl::shutdown()
{
}
