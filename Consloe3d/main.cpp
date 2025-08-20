#include <random>
#include <time.h>
#include "Utills.hpp"
#include "Circle.hpp"

int main() {

	srand(time(NULL));

	Utills utills;
    Circle circle(16,1.72);

    while (true) {
        utills.clearGameScreen();

        circle.draw();
        
        Sleep(30); 
    }

	return 0;

}
