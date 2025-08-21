#include "Circle.hpp"


Circle::Circle(int radius, float offset)
    : GameObject("@%#*+=-:.", offset), radius(radius)
{
    setBounciness();
    isDirection.X = 1;
    isDirection.Y = 1;
    move.X = bounciness.X;
    move.Y = 1;
}

void Circle::draw()
{
    std::string frame;
    frame.reserve(MAP_HEIGHT * (MAP_WIDTH + 1));

    int centerX = MAP_WIDTH / 2 + move.X;
    int centerY = MAP_HEIGHT / 2 + move.Y;

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

    if (isDirection.X) move.X++;
    else move.X--;

    if (isDirection.Y) move.Y++;
    else move.Y--;

    handlePos();
}


void Circle::setBounciness()
{
    this->bounciness.X = (rand() % 11) - 5;
    this->bounciness.Y = (rand() % 11) - 5;
}

void Circle::handlePos()
{
    if (move.X + radius >= MAP_WIDTH / 2)  isDirection.X = 0;
    if (move.X - radius <= -(MAP_WIDTH / 2)) isDirection.X = 1;

    float scaledRadiusY = radius / yOffset;

    if (move.Y + scaledRadiusY >= MAP_HEIGHT / 2) isDirection.Y = 0;
    if (move.Y - scaledRadiusY <= -(MAP_HEIGHT / 2)) isDirection.Y = 1;
}