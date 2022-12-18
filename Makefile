# path to djgpp compiler
CC = /opt/djgpp/bin/i586-pc-msdosdjgpp-g++

# used to map compiler to correct libraries and headers
SETENV = /opt/djgpp/setenv

# used to link to Allegro game library
CFLAGS = -I external/allegro/include/
LIBS = -L external/allegro/lib/ -lalleg

# set source files
SOURCES = 	src/main.cpp src/game.cpp \
			src/playerPaddle/playerPaddle.cpp \
			src/playerPaddle/playerInput.cpp \
			src/sceneManager.cpp \
			src/scenes/splashScene.cpp \
			src/scenes/titleScene.cpp \
			src/scenes/playScene.cpp \
			src/scenes/winScene.cpp \
			src/scenes/loseScene.cpp \
			src/scenes/creditsScene.cpp

# name of resulting EXE
EXE = -o ./bin/DOSPONG

# target MS-DOS and FreeDOS
dos:
	$(SETENV) && $(CC) $(CFLAGS) $(SOURCES) $(LIBS) -O2 $(EXE).exe -DNDEBUG

run-dos:
	dosbox ./bin/DOSPONG.exe

run-linux:
	cd bin && ./dospong

# target Linux (for easy source-level debugging)
linux:
	g++ -ggdb -O0 $(SOURCES) -lalleg-debug -o bin/dospong


clean:
	rm -rf bin/DOSPON*
	rm -rf bin/dospong
