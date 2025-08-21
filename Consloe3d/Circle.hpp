#ifndef CIRCLE_H
#define CIRCLE_H
#include "GameObject.hpp"
#include "Vector2.hpp"
#include "config.hpp"

class Circle : protected GameObject {
private:
	int radius;
	Vector2 bounciness;
	int moveX = 1;
	Vector2 isDirection;

public:

	Circle(int radius, float offset);

	void draw() override;
	void setBounciness();

	void handlePos() override;

};

#endif