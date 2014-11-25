all: hw1_run
	
ifdef SCENE
MACRO += -DSCENE_FILE=\"$(SCENE)\"
endif
ifdef LIGHT
MACRO += -DLIGHT_FILE=\"$(LIGHT)\"
endif
ifdef VIEW
MACRO += -DVIEW_FILE=\"$(VIEW)\"
endif

LINK += -lGL -lGLU -lGLEW -lglut -lfreeimage
CFLAGS += $(MACRO)

TARGETS += display/mesh.o
display/mesh.o: display/mesh.cpp display/mesh.h
	g++ $(CFLAGS) -Wno-conversion-null -c -o display/mesh.o display/mesh.cpp

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

TARGETS += display/texture.o
display/texture.o: display/texture.h display/texture.cpp
	g++ $(CFLAGS) -c -o display/texture.o display/texture.cpp

TARGETS += display.o
display.o: header.h display/viewing.h display/scene.h display/object.h display/mesh.h display/light.h display.cpp
	g++ $(CFLAGS) -c -o display.o display.cpp

TARGETS += kbd_mouse.o
kbd_mouse.o: header.h display/viewing.h display/scene.h display/object.h display/mesh.h display/light.h kbd_mouse.cpp
	g++ $(CFLAGS) -c -o kbd_mouse.o kbd_mouse.cpp

TARGETS += main.o
main.o: header.h display/viewing.h display/scene.h display/object.h display/mesh.h display/light.h main.cpp
	g++ $(CFLAGS) -c -o main.o main.cpp

hw1_run: $(TARGETS) header.h display/viewing.h display/scene.h display/object.h display/mesh.h display/light.h
	g++ $(CFLAGS) $(LINK) -o hw1_run $(TARGETS)

.PHONY: clean
clean:
	rm -f $(TARGETS) hw1_run
