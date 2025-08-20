#include <iostream>
#include "config.hpp"
#include <string.h>
#include <random>
#include <time.h>
#include "Utills.hpp"

int main() {

	srand(time(NULL));

	std::string gradient = "@%#*+=-:.";
	Utills utills;

	int radius = 16;
	float xOffset = 1.72;
	int moveRight = 1;
	bool isRight = true;


    while (true) {
        utills.clearGameScreen();

        std::string frame;
        frame.reserve(MAP_HEIGHT * (MAP_WIDTH + 1));

        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                float dx = (i - MAP_HEIGHT / 2) * xOffset;
                float dy = j - MAP_WIDTH / 2 - moveRight;
                float dist = sqrt(dx * dx + dy * dy);

                if (dist < radius) {
                    float norm = dist / radius;
                    int idx = (int)(norm * (gradient.size() - 1));
                    frame += gradient[idx];
                }
                else {
                    frame += ' ';
                }
            }
            frame += '\n';
        }

        std::cout << frame;

        if (isRight) moveRight++;
        else moveRight--;
        if (moveRight == 44) isRight = false;
        if (moveRight == -44) isRight = true;

        Sleep(30); 
    }

	return 0;
}
