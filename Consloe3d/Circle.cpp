#include "Circle.hpp"


Circle::Circle(int radius, float offset)
    : GameObject("@%#*+=-:.", offset), radius(radius)
{
}

void Circle::draw()
{

    std::string frame;
    frame.reserve(MAP_HEIGHT * (MAP_WIDTH + 1));

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            float dx = (i - MAP_HEIGHT / 2) * yOffset;
            float dy = j - MAP_WIDTH / 2 - moveX;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist < radius) {
                float norm = dist / radius;
                int idx = (int)(norm * (gradient.size() - 1));
                frame += gradient[idx];
                if (moveX == (MAP_WIDTH/2)-radius) isXdirection = false;
                if (moveX == -((MAP_WIDTH / 2) - radius)) isXdirection = true;
            }
            else {
                frame += ' ';
            }
        }
        frame += '\n';
    }

    std::cout << frame;

    if (isXdirection) moveX++;
    else moveX--;

}
