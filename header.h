#pragma once

#include <GL/glut.h>
#include "display/light.h"
#include "display/scene.h"
#include "display/viewing.h"

#define SCENE_FILE "scene.scene"
#define LIGHT_FILE "light.light"
#define VIEW_FILE "view.view"

void display();
void reshape(GLsizei, GLsizei);
//void keyboard(unsigned char, int, int);
//void mouse(int, int, int, int);

LightLoader &returnLight();
SceneLoader &returnScene();
ViewingLoader &returnView();

