# path to djgpp compiler
CC = /opt/djgpp/bin/i586-pc-msdosdjgpp-g++

# used to map compiler to correct libraries and headers
SETENV = /opt/djgpp/setenv

# used to link to Allegro game library
CFLAGS = -I external/allegro/include/
LIBS = -L external/allegro/lib/ -lalleg

# set source files
SOURCES = src/main.cpp src/game.cpp
#SOURCES = src/main.c src/ldp_game.c src/ldp_entity.c \
#		  src/ldp_player1.c

# name of resulting EXE
EXE = -o ./bin/DOSPONG

# target MS-DOS and FreeDOS
dos:
	$(SETENV) && $(CC) $(CFLAGS) $(SOURCES) $(LIBS) -O2 $(EXE).exe

run:
	dosbox ./bin/DOSPONG.exe

# target Linux (for easy source-level debugging)
linux:
	gcc -ggdb -O0 $(SOURCES) -lalleg-debug -o bin/dospong
	cd ./bin/ && ./dospong


clean:
	rm -rf bin/DOSPON*
	rm -rf bin/dospong
