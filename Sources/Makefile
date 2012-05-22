NewUniverse : main.o core.o interface_SDL.o
	g++ -o NewUniverse main.o core.o interface_SDL.o -lSDL -lSDL_image -lSDL_ttf

main.o : main.cpp
	g++ -c main.cpp -lSDL -lSDL_image -lSDL_ttf

core.o : core.cpp core.h
	g++ -c core.cpp -lSDL -lSDL_image -lSDL_ttf

interface_SDL.o : interface_SDL.cpp interface_SDL.h
	g++ -c interface_SDL.cpp -lSDL -lSDL_image -lSDL_ttf

clean :
	rm -f *.o

