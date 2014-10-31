all: hw1_run
	

LINK += -lGL -lGLU -lglut
CFLAGS = ""

hw1_run: $(TARGETS) $(INCLUDES)
	g++ $(CFLAGS) $(LINK) -o hw1_run $(TARGETS)

TARGETS += loader/mesh.o
INCLUDES += loader/mesh.h
loader/mesh.o: loader/mesh.cpp loader/mesh.h
	g++ $(CFLAGS) -c -o loader/mesh.o loader/mesh.cpp
