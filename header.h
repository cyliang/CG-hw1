#pragma once

#include <GL/glew.h>
#include <GL/glut.h>
#include "display/light.h"
#include "display/scene.h"
#include "display/viewing.h"

#ifndef SCENE_FILE
#define SCENE_FILE "Chess.scene"
#endif
#ifndef LIGHT_FILE
#define LIGHT_FILE "Chess.light"
#endif
#ifndef VIEW_FILE
#define VIEW_FILE "Chess.view"
#endif

void display();
void reshape(GLsizei, GLsizei);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);

LightLoader &returnLight();
SceneLoader &returnScene();
ViewingLoader &returnView();

