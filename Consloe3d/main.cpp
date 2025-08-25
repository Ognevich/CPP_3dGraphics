#include "ProjectControl.hpp"

int main() {

	srand(time(NULL));

	ProjectControler project;

	project.init();
	project.run();
	project.shutdown();


	return 0;

}
