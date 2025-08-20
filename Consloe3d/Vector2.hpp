#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
private:
	int posX;
	int posY;
public:
	Vector2(int curr_posX, int curr_posY);

	int getXvalue();
	int getYvalue();

	void setXvalue(int posX);
	void setYvalue(int posY);


};

#endif