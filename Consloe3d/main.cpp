#include "ProjectControl.h"

int main() {

	srand(time(NULL));

	ProjectControl project;

	project.init();
	project.run();
	project.shutdown();


	return 0;

}
