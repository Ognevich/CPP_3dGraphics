#ifndef CIRCLE_H
#define CIRCLE_H

#include "Objects.hpp"
#include <string>

class Circle : public GameObjects {
private:
    int radius;

public:
    Circle(int radius, float offset, const std::string& grad = "@%#*+=-:.");

    void saveObjectCoordToVector() override;
    char createGradient(float dist) override;

    int getRadius() const { return radius; }
    float calculateSquareDistance(int posX, int posY) const;

    Vector2 getFuturePos() override;
};

#endif