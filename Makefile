all: hw1_run
	

LINK += -lGL -lGLU -lglut
CFLAGS = ""

hw1_run: $(TARGETS) $(INCLUDES)
	g++ $(CFLAGS) $(LINK) -o hw1_run $(TARGETS)

TARGETS += display/mesh.o
INCLUDES += display/mesh.h
loader/mesh.o: display/mesh.cpp display/mesh.h
	g++ $(CFLAGS) -c -o display/mesh.o display/mesh.cpp
