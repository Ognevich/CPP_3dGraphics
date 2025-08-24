#ifndef PROJECT_CONTROL_H
#define PROJECT_CONTROL_H
#include "config.hpp"
#include "Utills.hpp"
#include "Circle.hpp"
#include "Map.hpp"

class ProjectControl {
private:
	Map map;
public:
	void init();
	void run();
	void shutdown();

};

#endif
