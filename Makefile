all: hw1_run
	

LINK += -lGL -lGLU -lglut
CFLAGS = 

hw1_run: $(TARGETS) header.h
	g++ $(CFLAGS) $(LINK) -o hw1_run $(TARGETS)

TARGETS += display/mesh.o
display/mesh.o: display/mesh.cpp display/mesh.h
	g++ $(CFLAGS) -c -o display/mesh.o display/mesh.cpp


TARGETS += display/light.o
display/light.o: display/light.h display/light.cpp
	g++ $(CFLAGS) -c -o display/light.o display/light.cpp

TARGETS += display/object.o
display/object.o: display/mesh.h display/object.h display/object.cpp
	g++ $(CFLAGS) -c -o display/object.o display/object.cpp

TARGETS += display/scene.o
display/scene.o: display/mesh.h display/object.h display/scene.h display/scene.cpp
	g++ $(CFLAGS) -c -o display/scene.o display/scene.cpp

TARGETS += display/viewing.o
display/viewing.o: display/viewing.h display/viewing.cpp
	g++ $(CFLAGS) -c -o display/viewing.o display/viewing.cpp
