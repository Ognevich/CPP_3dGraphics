#include <random>
#include "config.hpp"
#include "Utills.hpp"
#include "Circle.hpp"

int main() {

	srand(time(NULL));

	Utills utills;
    Circle circle(2,1.72);

    while (true) {
        utills.clearGameScreen();

        circle.draw();
        
        Sleep(30); 
    }

	return 0;

}
