#ifndef SQUARE_H
#define SQUARE_H

#include "Objects.hpp"
#include <string>

class Square : public GameObjects {
private:
    int radius;

public:
    Square(int radius, float offset, const std::string& grad = "@%#*+=-:.");

    void saveObjectCoordToVector() override;
    char createGradient(float dist) override;

    int getRadius() const { return radius; }
    float calculateSquareDistance(int posX, int posY) const;

};

#endif
