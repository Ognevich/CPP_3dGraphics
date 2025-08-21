#include "Circle.hpp"


Circle::Circle(int radius, float offset)
    : GameObject("@%#*+=-:.", offset), radius(radius)
{
    isDirection.X = 1;
    isDirection.Y = 1;
}

void Circle::draw()
{

    std::string frame;
    frame.reserve(MAP_HEIGHT * (MAP_WIDTH + 1));

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            float dy = (i - MAP_HEIGHT / 2) * yOffset; /*+ bounciness.getYvalue();*/
            float dx = j - MAP_WIDTH / 2 - moveX;/*bounciness.getXvalue();*/
            float dist = sqrt(dx * dx + dy * dy);

            if (dist < radius) {
                float norm = dist / radius;
                int idx = (int)(norm * (gradient.size() - 1));
                frame += gradient[idx];
                handlePos();
            }
            else {
                frame += ' ';
            }
        }
        frame += '\n';
    }

    std::cout << frame;

    if (isDirection.X) moveX++;
    else moveX--;

}

void Circle::setBounciness()
{
    this->bounciness.X = (rand() % 11) - 5;
    this->bounciness.Y = (rand() % 11) - 5;
}

void Circle::handlePos()
{
    if (moveX == (MAP_WIDTH / 2) - radius) isDirection.X = 0;
    if (moveX == -((MAP_WIDTH / 2) - radius)) isDirection.X = 1;
    setBounciness();
}
