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
    Vector2 pos;

public:
    GameObjects(const std::string& grad = "@%#*+=-:.", float offset = 1.72f);

    virtual ~GameObjects() = default;

    virtual char createGradient(float dist) = 0;
    virtual void saveObjectCoordToVector() = 0;

    virtual int getObjectCoordVectorLength() const;

    virtual const std::vector<Vector2>& getObjectCoords();

    virtual float getYOffset() const;

    virtual void invertDirectionX();
    virtual void invertDirectionY();

    virtual Vector2 getDirection() const;

    Vector2 getPos() const;

    std::vector<Vector2> getFutureCoord() const;
    std::vector<Vector2> getFutureCoordVectorX() const;
    std::vector<Vector2> getFutureCoordVectorY() const;

    void setPos(Vector2 p);
};
#endif