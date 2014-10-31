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
