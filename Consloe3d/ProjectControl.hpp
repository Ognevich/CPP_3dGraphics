#ifndef PROJECT_CONTROL_H
#define PROJECT_CONTROL_H
#include "config.hpp"
#include "Utills.hpp"
#include "Circle.hpp"
#include "Map.hpp"

class ProjectControler {
private:
	Map map;
	std::vector<Circle> circleVector;

public:
	ProjectControler();

	void init();
	void run();
	void shutdown();

	void addRandomCirclesToVector(int circleAmount);

};

#endif
