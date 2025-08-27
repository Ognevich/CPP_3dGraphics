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
    GameObjects(const std::string& grad = "@%#*+=-:.", float offset = 1.72f)
        : gradient(grad), yOffset(offset), pos{ 0,0 }, Direction{ 1,1 } {
    }

    virtual ~GameObjects() = default;

    virtual char createGradient(float dist) = 0;
    virtual void saveObjectCoordToVector() = 0;

    virtual int getObjectCoordVectorLength() const {
        return static_cast<int>(objectCoords.size());
    }

    virtual const std::vector<Vector2>& getObjectCoords() const {
        return objectCoords;
    }

    virtual float getYOffset() const { return yOffset; }

    virtual void invertDirectionX() { Direction.X = -Direction.X; }
    virtual void invertDirectionY() { Direction.Y = -Direction.Y; }
    
    // TEST, DELETE AFTER TESTING
    virtual void setDirectionX(int newDir) { Direction.X = newDir; }
    virtual void setDirectionY(int newDir) { Direction.Y = newDir; }
    // TEST

    virtual Vector2 getDirection() const { return Direction; }

    Vector2 getPos() const { return pos; }

    std::vector<Vector2> getFutureCoord() const {
        std::vector<Vector2> future;
        for (auto& coord : objectCoords) {
            future.push_back({ coord.X + Direction.X, coord.Y + Direction.Y });
        }
        return future;
    }

    void setPos(Vector2 p) { pos = p; }
};

#endif