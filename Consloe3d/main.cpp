#include "ProjectControl.hpp"

int main() {

	srand(time(NULL));

	ProjectControl project;

	project.init();
	project.run();
	project.shutdown();


	return 0;

}
