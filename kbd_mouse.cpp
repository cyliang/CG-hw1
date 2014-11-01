#include "header.h"

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
	case 'w':
		returnView().zoom(true);
		break;
	case 's':
		returnView().zoom(false);
		break;
	case 'a':
		returnView().rotate(true);
		break;
	case 'd':
		returnView().rotate(false);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}
