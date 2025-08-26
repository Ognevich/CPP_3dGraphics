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

	void saveObjectCoordToVector() override;
	void setPos(Vector2 pos);
	void setIsDirectionX(int isDirection);
	void setIsDirectionY(int isDirection);

	char createGradient(int radius, float dist) override;

	const std::vector<Vector2>& getObjectCoords() const override;
	Vector2 getPos();
	Vector2 getIsDirection();

	bool isObjectCoordVectorValue(int xPos, int yPos) override;
	int getRadius();
	int getObjectCoordVectorLenght() override;
	float calculateSquareDistance(int posX, int posY);
	float getyOffset() override;
};

#endif