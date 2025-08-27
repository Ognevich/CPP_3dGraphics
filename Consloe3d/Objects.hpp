#ifndef OBJECTS_H
#define OBJECTS_H

#include "config.hpp"
#include "Vector2.hpp"
#include <vector>
#include <string>

class GameObjects {
protected:
    std::string gradient;
    float yOffset;
    std::vector<Vector2> objectCoords;
    Vector2 Direction;

public:
    GameObjects(const std::string& grad = "@%#*+=-:.", float offset = 1.72f)
        : gradient(grad), yOffset(offset) {
    }

    virtual ~GameObjects() = default;

    virtual char createGradient(int radius, float dist) = 0;
    virtual void saveObjectCoordToVector() = 0;

    virtual int getObjectCoordVectorLength() const {
        return static_cast<int>(objectCoords.size());
    }

    virtual const std::vector<Vector2>& getObjectCoords() const {
        return objectCoords;
    }

    virtual float getYOffset() const { return yOffset; }

    virtual void invertDirectionX() = 0;
    virtual void invertDirectionY() = 0;
    virtual Vector2 getDirection() const = 0;
};

#endif // OBJECTS_H