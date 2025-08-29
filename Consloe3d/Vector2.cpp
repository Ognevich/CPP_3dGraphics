#include "Vector2.hpp"




Vector2::Vector2()
	: X(0), Y(0)
{


}

Vector2::Vector2(int curr_posX, int curr_posY) :X(curr_posX), Y(curr_posY) {
}

Vector2::Vector2(float curr_posXf, float curr_posYf)
	: Xf(curr_posXf), Yf(curr_posYf)
{
}
