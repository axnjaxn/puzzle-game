APPNAME = puzzle
ifndef CYGWIN
EXT = 
else
EXT = .exe
endif
APP = $(APPNAME)$(EXT)
CFLAGS = -g `sdl-config --cflags`
LFLAGS = -g `sdl-config --libs`

OBJECT_FILES = main.o

all: $(APP)

rebuild: clean $(APP)

.cpp.o:
	g++ -c $< $(CFLAGS)o

$(APP): $(OBJECT_FILES)
	g++ $(OBJECT_FILES) -o $(APP) $(LFLAGS)

run: $(APP)
	./$(APP)

clean:
	rm -f *~ *.o $(APP) Thumbs.db *.stackdump
