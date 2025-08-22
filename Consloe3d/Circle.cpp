#include "Circle.hpp"


Circle::Circle(int radius, float offset)
    : GameObject("@%#*+=-:.", offset), radius(radius)
{
    isDirection.X = rand() %3 -1;
    isDirection.Y = rand() %3 -1;
    pos.X = (rand() % (MAP_WIDTH - 2 * radius)) - (MAP_WIDTH / 2 - radius);
    pos.Y = (rand() % (MAP_HEIGHT - 2 * (int)(radius / yOffset))) - (MAP_HEIGHT / 2 - (int)(radius / yOffset));
    
}

void Circle::draw()
{
    std::string frame;
    frame.reserve(MAP_HEIGHT * (MAP_WIDTH + 1));

    int centerX = MAP_WIDTH / 2 + pos.X;
    int centerY = MAP_HEIGHT / 2 + pos.Y;

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            float dx = j - centerX;
            float dy = (i - centerY) * yOffset;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist < radius) {
                float norm = dist / radius;
                int idx = (int)(norm * (gradient.size() - 1));
                frame += gradient[idx];
            }
            else {
                frame += ' ';
            }
        }
        frame += '\n';
    }

    std::cout << frame;

    if (isDirection.X) pos.X++;
    else pos.X--;

    if (isDirection.Y) pos.Y++;
    else pos.Y--;

    updatePos();
}

void Circle::updatePos()
{
    if (pos.X + radius >= MAP_WIDTH / 2)  isDirection.X = 0;
    if (pos.X - radius <= -(MAP_WIDTH / 2)) isDirection.X = 1;

    float scaledRadiusY = radius / yOffset;

    if (pos.Y + scaledRadiusY >= MAP_HEIGHT / 2) isDirection.Y = 0;
    if (pos.Y - scaledRadiusY <= -(MAP_HEIGHT / 2)) isDirection.Y = 1;
}