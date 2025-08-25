#ifndef CIRCLE_H
#define CIRCLE_H
#include "Objects.hpp"
#include "config.hpp"
#include "Vector2.hpp"
#include <vector>

class Circle : protected GameObjects {
private:
	int radius;
	Vector2 bounciness;
	Vector2 pos;
	Vector2 velocity;
	Vector2 isDirection;

public:

	Circle(int radius, float offset);

	void updateObjectPos() override;
	void saveObjectCoordToVector() override;
	char createGradient(int radius, float dist) override;
	int getObjectCoordVectorLenght() override;
	bool isObjectCoordVectorValue(int xPos, int yPos) override;
	const std::vector<Vector2>& getObjectCoords() const override;
	float calculateSquareDistance(int posX, int posY);
	Vector2 getPos();
	int getRadius();
};

#endif