#ifndef CIRCLE_H
#define CIRCLE_H
#include "GameObject.hpp"
#include "Vector2.hpp"
#include "config.hpp"

class Circle : protected GameObject {
private:
	int radius;
	int moveX = 1;
	bool isXdirection = true;
public:

	Circle(int radius, float offset);

	void draw() override;

};

#endif