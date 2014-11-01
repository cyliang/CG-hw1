#include "header.h"

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(returnView().getWidth(), returnView().getHeight());
	glutCreateWindow("GL-Assignment1 0116229");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glutMouseFunc(/* TODO */);
	glutMainLoop();
	return 0;
}

void reshape(GLsizei, GLsizei) {
	returnView().setViewing();
}

LightLoader &returnLight() {
	static LightLoader light(LIGHT_FILE);
	return light;
}

SceneLoader &returnScene() {
	static SceneLoader scene(SCENE_FILE);
	return scene;
}

ViewingLoader &returnView() {
	static ViewingLoader view(VIEW_FILE);
	return view;
}
