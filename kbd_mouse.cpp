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
		if(key >= '1' && key <= '9') {
			returnScene().select(key - '1');
		}
		break;
	}

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	static int startX, startY;
	if(state == GLUT_DOWN) {
		startX = x;
		startY = y;
	} else if(state == GLUT_UP) {
		returnScene().moveObj(x - startX, y - startY);
		glutPostRedisplay();
	}
}
