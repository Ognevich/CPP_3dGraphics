#include "Vector2.hpp"

Vector2::Vector2(int curr_posX, int curr_posY) : posX(curr_posX), posY(curr_posY) {
}

int Vector2::getXvalue()
{
	return this->posX;
}
int Vector2::getYvalue()
{
	return this->posY;
}

void Vector2::setXvalue(int posX)
{
	this->posX = posX;
}

void Vector2::setYvalue(int posY)
{
	this->posY = posY;
}