#ifndef OBJECTS_H
#define OBJECTS_H
#include "config.hpp"

class GameObject {
protected:
	std::string gradient;
	float yOffset;

	virtual void updatePos() = 0;

public:
	GameObject(const std::string& grad = "@%#*+=-:.", float offset = 1.72f)
		: gradient(grad), yOffset(offset) {
	}

	virtual void draw() = 0;
	virtual char createGradient(int radius, int dist) = 0;
};

#endif