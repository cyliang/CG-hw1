#include "header.h"

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	returnView().setViewing();
	returnLight().setLight();
	returnScene().displayScene();

	glutSwapBuffers();
	glFlush();
}
