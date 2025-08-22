#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
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

};

#endif