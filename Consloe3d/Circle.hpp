#ifndef CIRCLE_H
#define CIRCLE_H

#include "Objects.hpp"
#include "config.hpp"
#include "Vector2.hpp"
#include <vector>

class Circle : public GameObjects {
private:
    int radius;
    Vector2 pos;

public:
    Circle(int radius, float offset, const std::string& grad = "@%#*+=-:.");

    void saveObjectCoordToVector() override;

    void setPos(Vector2 pos);
    Vector2 getPos() const;

    void invertDirectionX() override;
    void invertDirectionY() override;

    char createGradient(int radius, float dist) override;
    Vector2 getDirection() const override;

    int getRadius() const;
    float calculateSquareDistance(int posX, int posY) const;
};

#endif // CIRCLE_H
