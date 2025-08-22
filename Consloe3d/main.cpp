#include <random>
#include "config.hpp"
#include "Utills.hpp"
#include "Circle.hpp"

int main() {

	srand(time(NULL));

	Utills utills;
    Circle circle(4,1.72);
    Circle circle2(4, 1.72);

    while (true) {
        utills.clearGameScreen();

        circle.draw();
        circle2.draw();

        Sleep(30); 
    }

	return 0;

}
