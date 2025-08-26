#ifndef OBJECTS_H
#define OBJECTS_H
#include "config.hpp"
#include "Vector2.hpp"

class GameObjects {
protected:
	std::string gradient;
	float yOffset;
	std::vector<Vector2> objectCoords;

public:
	GameObjects(const std::string& grad = "@%#*+=-:.", float offset = 1.72f)
		: gradient(grad), yOffset(offset) {
	}

	virtual char createGradient(int radius, float dist) = 0;
	virtual void saveObjectCoordToVector() = 0;
	virtual int getObjectCoordVectorLenght() = 0;
	virtual const std::vector<Vector2>& getObjectCoords() const = 0;
	virtual bool isObjectCoordVectorValue(int xPos, int yPos) = 0;

	virtual float getyOffset() = 0;

};

#endif