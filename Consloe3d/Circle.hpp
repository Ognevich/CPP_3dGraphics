#ifndef CIRCLE_H
#define CIRCLE_H
#include "GameObject.hpp"
#include "Vector2.hpp"
#include "config.hpp"

class Circle : protected GameObject {
private:
	int radius;
	Vector2 bounciness;
	Vector2 move;
	Vector2 isDirection;

public:

	Circle(int radius, float offset);

	void draw() override;
	void setBounciness();

	void handlePos() override;

};

#endif