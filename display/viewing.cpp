#include "viewing.h"
#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

ViewingLoader::ViewingLoader(const char *file_name) {
	std::ifstream ifile(file_name, std::ios::in);
	if(!ifile) {
		std::cerr << "Cannot load the viewing file: " << file_name << std::endl;
		exit(1);
	}

	std::string item;
	bool searched_item[7] = {0};
	while(ifile >> item) {
		if(item == "eye") {
			ifile >> eye_xyz[0] >> eye_xyz[1] >> eye_xyz[2];
			searched_item[0] = true;
		} else if(item == "vat") {
			ifile >> vat_xyz[0] >> vat_xyz[1] >> vat_xyz[2];
			searched_item[1] = true;
		} else if(item == "vup") {
			ifile >> vup_xyz[0] >> vup_xyz[1] >> vup_xyz[2];
			searched_item[2] = true;
		} else if(item == "fovy") {
			ifile >> fovy;
			searched_item[3] = true;
		} else if(item == "dnear") {
			ifile >> dnear;
			searched_item[4] = true;
		} else if(item == "dfar") {
			ifile >> dfar;
			searched_item[5] = true;
		} else if(item == "viewport") {
			ifile >> viewport_xywh[0] >> viewport_xywh[1] >> viewport_xywh[2] >> viewport_xywh[3];
			searched_item[6] = true;
		} else {
			std::cerr << "Error in parsing viewing file: " << file_name << std::endl;
			exit(1);
		}

		if(!ifile) {
			std::cerr << "Error in parsing viewing file: " << file_name << std::endl;
			exit(1);
		}
	}

	for(int i=0; i<7; i++) {
		if(!searched_item[i]) {
			std::cerr << "Missing information in viewing file: " << file_name << std::endl;
			exit(1);
		}
	}
}

void ViewingLoader::setViewing() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		eye_xyz[0], eye_xyz[1], eye_xyz[2],
		vat_xyz[0], vat_xyz[1], vat_xyz[2],
		vup_xyz[0], vup_xyz[1], vup_xyz[2]
	);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewport_xywh[2] / viewport_xywh[3], dnear, dfar);

	glViewport(viewport_xywh[0], viewport_xywh[1], viewport_xywh[2], viewport_xywh[3]);
}
